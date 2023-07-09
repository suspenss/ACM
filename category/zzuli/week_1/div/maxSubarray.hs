import qualified Data.Text as Tx
import qualified Data.Text.IO as Tio
import Data.Char (ord)

main = do
    getLine
    inputs <- map (parse . Tx.unpack) 
              . Tx.words <$> Tio.getLine :: IO [Int]
    print $ solve inputs

solve :: [Int] -> Int
solve = maximum . drop 1 . scanl (\acc x -> max 0 acc + x) 0

parse :: String -> Int
parse l@(x: xs) = case x of
    '-' -> negate . parse' $ xs 
    _   -> parse' l 
    where  parse' = foldl (\acc x -> acc * 10 + (ord x - ord '0')) 0 