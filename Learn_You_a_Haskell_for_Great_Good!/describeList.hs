describeList :: [a] -> String
describeList ls = "The list is "
                  ++ case ls of [] -> "empty."
                                [_] -> "a singleton list."
                                xs -> "a longer list."

describeList' :: [a] -> String
describeList' ls = "The list is " ++ what ls
    where what []  = "empty."
          what [_] = "a singleton list."
          what ls  = "a longer list."
