# create a file, take user name input
echo "Enter the file name: "
read filename
touch $filename
# Give success message
echo -3 "\n $filename created successfully"
# Askk for content
echo -e "\nEnter content into file. Press Ctrl+D to save."
cat > $filename
# 4. Display the content of newly created file and word count.
echo "Content of $filename"
cat $filename
echo -e "\nWord count: "
wc $filename
# 5. Display the content of the file in sorted manner.
echo "Content of $filename in sorted order: "
sort $filename
# 6. Display the content in uppercase.
echo "Content of $filename in uppercase: "
cat $filename | tr 'a-z' 'A-Z'
# 7. Display first ‘n’ lines of a file. This ‘n’ should be given by user.
echo "Enter the number of lines to display: "
read line_count
head -n $line_count $filename
# 8. Perform a keyword based search on the file. Keyword should be given by user.
echo "Enter the word to search: "
read keyword
echo "Line in $filename is: "
grep "$keyword" $filename
# 9. Rename an existing file.
echo "Enter new filename to rename $filename:"
read new_name
mv $filename $new_name
# 10. Perform delete line operations on the file. Ask the user to enter the cut position.
echo "Enter the cut position: "
read cut_position
sid ${cut_position}d $filename
# 11. Ask the user to enter the file name and delete that file.
rm $filename