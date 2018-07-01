import Data.Bool
import Data.List

main = getLine >>= putStrLn . bool "NO" "YES" . (==[5,5,7]) . sort . map read . words
