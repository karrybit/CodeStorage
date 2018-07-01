import Control.Monad
import Data.List

main = do
    [n, _] <- (map read . words) <$> getLine :: IO [Int]
    ss <- sort <$> replicateM n getLine :: IO [String]
    putStrLn $ intercalate ""  ss
