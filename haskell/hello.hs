main = do
putStrLn "Hello World"
putStrLn "Welcome"
name <- getLine
putStrLn ("Welcome " ++ name ++ " to Haskell Programming!")
--print(isNegative 12.4)
print(max 2 3)

max :: Int -> Int -> Int
max i j | (i >= j) = i
        | (i < j)  = j

-- isNegative :: Float -> Bool
-- isNegative num
--    | num < 0 = False
--   | num > 0 = True

-- myCompare :: Integer -> Integer -> String
-- myCompare a b
--  | a < b  = "A is less than B"
--  | a > b  = "A is greater than B"
--  | a == b = "A equals B"
