describeList :: [a] -> String
describeList ls = "The list is "
                  ++ case ls of [] -> "empty"
                                [_] -> "a singleton list."
                                xs -> "a longer list."
