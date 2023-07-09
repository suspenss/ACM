import qualified Data.Text as Text
import qualified Data.Text.IO as Tio
import Data.Char (ord)

main = do
    n <- parse . Text.unpack <$> Tio.getLine :: IO Int
    print $ ans (n - 4)

stand = zip [0..9] [6, 2, 4, 5, 4, 5, 6, 3, 7, 6]

ans :: Int -> Int
ans n = length [ (x, y, z) | 
    x <- stand, y <- stand, z <- stand, 
    (\(a, cnt1) (b, cnt2) (c, cnt3) -> a + b == c && cnt1 + cnt2 + cnt3 == n) x y z]

parse :: String -> Int
parse = foldl (\acc x -> acc * 10 + (ord x - ord '0')) 0