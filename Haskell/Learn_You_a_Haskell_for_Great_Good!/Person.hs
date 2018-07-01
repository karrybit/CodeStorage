data Person = Person { firstName :: String
                     , lastName :: String
                     , age :: Int
                     } deriving (Eq, Show, Read)

mysteryDude = "Person { firstName = \"Michael\"" ++
                     ", lastName = \"Diamond\"" ++
                     ", age = 43}"
