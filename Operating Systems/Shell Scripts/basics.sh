# create a file, take user name input
echo "Enter the file name: "
read filename
touch $filename
# Give success message
echo -e "\n $filename created successfully"
# Askk for content
echo -e "\nEnter content into file. Press Ctrl+D to save."
cat > $filename
# 4. Display the content of newly created file and word count.
echo -e "\nContent of $filename"
cat $filename
echo -e "\nWord count: "
wc $filename
# 5. Display the content of the file in sorted manner.
echo "Content of $filename in sorted order: "
sort $filename
# 6. Display the content in uppercase.
echo -e "\nContent of $filename in uppercase: "
cat $filename | tr 'a-z' 'A-Z'
# 7. Display first ‘n’ lines of a file. This ‘n’ should be given by user.
echo -e "\nEnter the number of lines to display: "
read line_count
head -n $line_count $filename
# 8. Perform a keyword based search on the file. Keyword should be given by user.
echo -e "\nEnter the word to search: "
read keyword
echo "Line in $filename is: "
grep "$keyword" $filename
# 9. Rename an existing file.
echo -e "\nEnter new filename to rename $filename:"
read new_name
mv $filename $new_name
# 10. Perform delete line operations on the file. Ask the user to enter the cut position.
echo -e "\nEnter the cut position: "
read cut_position
sid ${cut_position}d $filename
# 11. Ask the user to enter the file name and delete that file.
rm $new_name

#-------------------------------------------------------------
expr 10 + 20
expr 13 \* 2
expr 13 / 2
expr 13 % 9
myVal1 = ${expr 30 / ${expr 5 \* 2}}
expr substr "a b c d e" 1 1
echo "55 / 3" | bc
# -l creates exact output
echo "55 / 3" | bc -l
echo "scale=3 55 / 3" | bc

#---------------------Assignment 4----------------------------
echo "Enter a value"
read a
echo "Enter a value"
read b
val1 = ${echo "$a + $b" | bc}
echo "Addition: $val1"
val1 = ${echo "$a - $b" | bc}
echo "Subtraction: $val1"
val1 = ${echo "$a \* $b" | bc}
echo "Multiplication: $val1"
val1 = ${echo "$a / $b" | bc -l}
echo "Division: $val1"
val1 = ${echo "$a % $b" | bc}
echo "Remainder: $val1"

if [ $a -gt $b]
then
    echo "$a"
elif [$a -lt $b]
then
    echo "$b"
else
    echo "Equal"
fi

val1 = $(echo "$a % 2" | bc)
if [ $val1 -eq 0 ]
then
    echo "a"
elif [  $val1 -eq 1 ]
then
    echo "b"
else
    echo "wtf"
fi

year = 2004
if [[ ($year % 4 -eq 0 && $year % 100 -ne 0) || ($year % 400 -eq 0) ]]; then
    echo "$year is a leap year."
else
    echo "$year is not a leap year."
fi

echo "Enter accoutn balance"
read balance

case "a" in
    "a")
        echo "vowel"
    ;;
    "b")
        echo "vowel"
    ;;
    "c")
        echo "vowel"
    ;;
    "d")
        echo "vowel"
    ;;
    "e")
        echo "vowel"
    ;;
    *)
        echo "consonant"
    ;;
esac

length = ${#val1}
case "length" in
    2)
        echo "2"
    ;;
    3)
        echo "3"
    ;;
    *)
        echo "consonant"
    ;;
esac

var1 = ${var2}${var3}

