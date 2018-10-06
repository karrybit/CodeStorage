main = do
    [n, a, b] <- map read . words <$> getLine
    print $ sum [k | k <- [1..n], a <= f k, f k <= b]

f k = sum [read [c] | c <- show k]