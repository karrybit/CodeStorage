replicate' :: Int -> a -> [a]
replicate' 0 _ = []
replicate' x y = y: replicate' (x -1) y
