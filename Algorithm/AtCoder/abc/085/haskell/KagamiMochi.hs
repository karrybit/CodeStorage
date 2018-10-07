import Control.Monad
import Data.List
main = do
    n <- readLn
    ds <- replicateM n readLn
    print $ length $ group $ sort (ds :: [Integer])