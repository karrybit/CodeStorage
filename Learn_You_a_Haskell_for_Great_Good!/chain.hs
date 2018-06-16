chain :: Integer -> [Integer]
chain n
    | n <= 0 = []
    | n == 1 = [1]
    | even n = n : chain (n `div` 2)
    | odd n = n : chain (n * 3 + 1)
