elem' :: (Eq a) => a -> [a] -> Bool
elem' _ [] = False
elem' x (l:ls) = if x == l
                 then True
                 else elem' x ls
