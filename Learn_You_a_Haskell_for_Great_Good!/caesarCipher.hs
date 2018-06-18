import Data.Char

encode :: Int -> String -> String
encode offset = map (\c -> chr $ ord c + offset)

decode :: Int -> String -> String
decode offset = map (\c -> chr $ ord c - offset)
