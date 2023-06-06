exitKey = ""
#A while loop that lets the code run recursively
while exitKey != "q":
#A map that takes input as integers and maps them to three keys. It's inside a try statement so that I can handle the possible errors.
    try:
        classHrs = {"class1":int(input("How many hours should you spend in class 1? ")),
                "class2":int(input("How many hours should you spend in class 2? ")),
                "class3":int(input("How many hours should you spend in class 3? "))}
#Two questions that take input as integers for how long the user actually studys and how many days of the week.
        studyDays = int(input("How many days a week do you typically study? "))
        avgStudy = int(input("How many hours a day do you think you study on average? "))
#We add all of our class hours together to get a total recommended study time.
        totalHrs = classHrs["class1"] + classHrs["class2"] + classHrs["class3"]
#We divide the total by the amount of days we want to study, returning an average study hours per desired day to meet recommendations.
        hoursDiv = totalHrs / studyDays
#An exception statement that checks for a value error.
    except ValueError:
        exitKey = input("You have to input a number! Run Again? Q to exit. ").lower()
#Return the hour recommended per day:
    else:
        print("You should spend this many hours studying per day: ", round(hoursDiv, 1))

#Evaluate whether you are above or below the recommended study hours.
        if avgStudy > hoursDiv:
            print("You are probably studying enough.")
        elif avgStudy < hoursDiv:
            print("Consider studying more, or your grades may suffer!")
        else:
            print("You meet the requirements! Good job, nerd.")
        exitKey = input("Run Again? Q to exit. ").lower()

exit(0)

