#Tutorial followed from freecodecamp.org

#FILE INPUT

employee_file = open("employees.txt", "r")
# r is read, w is write, a is append, r+ is read and write

# print(employee_file.readable())

for employee in employee_file.readlines():
    print(employee)

#doing this loop with readline prints out the line character by character?

#read reads whole file
#readlines puts everyline in a list
#readline to go line by line

employee_file.close()


#FILE OUTPUT
employee_file = open("employees2.txt", "a")

employee_file.write("\nKelly - Customer Services")

employee_file.close()

