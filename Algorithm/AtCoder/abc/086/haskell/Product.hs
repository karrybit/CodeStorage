main = do
    [a, b] <- map read . words <$> getLine
    if mod (a * b) 2 == 1
        then putStrLn "Odd"
        else putStrLn "Even"