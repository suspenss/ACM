import qualified Data.Text as Text
import qualified Data.Text.IO as Tio
import Data.Char (ord)
import qualified Data.Vector.Unboxed as V
import Data.Array

main = do
    [l, m, n] <- map (parse . Text.unpack) 
              . Text.words <$> Tio.getLine :: IO [Int]
    inputs <- map (parse . Text.unpack) <$> mapM (const Tio.getLine) [1..m]
    print $ binary 0 1 l (0: inputs ++ [l]) n
    -- print [l, m, n]

parse :: String -> Int
parse l@(x: xs) = case x of
    '-' -> negate . parse' $ xs 
     _  -> parse' l 
    where  parse' = foldl (\acc x -> acc * 10 + (ord x - ord '0')) 0 

judge :: Int -> [Int] -> Int -> Bool
judge len blocks finity
    | ans <= finity = True
    | ans > finity = False
     where 
        ans = ask 0 len blocks

ask :: Int -> Int -> [Int] -> Int
ask n _ [x] = n
ask n len (now: rest)
    | head rest - now < len = ask (n+1) len (now: drop 1 rest)
    | head rest - now >= len = ask n len rest 

-- binary search
binary ans left right blocks finity
    | left > right = ans
    | judge mid blocks finity = binary mid (mid + 1) right blocks finity
    | otherwise = binary ans left (mid - 1) blocks finity
    where
        mid = left + quot (right - left) 2 
