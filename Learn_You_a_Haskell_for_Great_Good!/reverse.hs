reverse' :: [a] -> [a]
reverse' [] = []
reverse' [a] = [a]
reverse' x = last x : init x
