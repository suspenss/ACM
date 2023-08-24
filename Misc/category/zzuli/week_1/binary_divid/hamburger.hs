main = do
   [b, s, c] <- ingredients <$> getLine 
   return ()

ingredients :: String -> [Int]
ingredients l = hamburger l 0 0 0 where
    hamburger :: String -> Int -> Int -> Int -> [Int]
    hamburger [] b s c = [b, s, c]
    hamburger (x: xs) b s c = case x of
        'B' -> hamburger xs (b + 1) s c
        'S' -> hamburger xs b (s + 1) c
        'C' -> hamburger xs b s (c + 1)