{-# LANGUAGE ScopedTypeVariables #-}

import Data.List

main = do
    [a, b, x] :: [Int]  <- map read . words <$> getLine
    print $ (b `div` x) - (( a - 1) `div` x)