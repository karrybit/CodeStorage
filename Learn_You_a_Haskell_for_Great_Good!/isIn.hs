import Data.List

isIn :: (Eq a) => [a] -> [a] -> Bool
needle `isIn` hayStack = any (needle `isPrefixOf`) (tails hayStack)
