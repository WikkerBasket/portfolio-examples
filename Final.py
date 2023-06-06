import csv
import turtle

def drawGraph(x, y, size, startpos, notch):
    size = size * 200
    numsX = 1
    numsY = 2
    #Draw axis X
    t.up()
    t.goto(-startpos, -startpos)
    t.down()
    t.forward(size)
    t.goto(-startpos, -startpos)
    #Draw notches X
    for i in range(len(x)):
        t.forward(notch)
        t.right(90)
        t.forward(5)
        t.back(5)
        t.up()
        #Writing the labels for each of the notches on X-axis
        t.forward(25)
        t.write(numsX)
        t.back(25)
        t.down()
        t.left(90)
        numsX += 1
    #Draw label X
    t.up()
    #The raw transforming done here is just to center the text a bit better.
    t.goto(-(scale/startpos - 50),(-startpos - 60))
    t.write("Days")
    #Draw axis Y
    t.up()
    t.goto(-startpos, -startpos)
    t.left(90)
    t.down()
    t.forward(size)
    t.goto(-startpos, -startpos)
    #Draw notches Y
    for i in range(len(y)):
        t.forward(notch)
        t.left(90)
        t.forward(5)
        t.back(5)
        t.up()
        #Writing the labels for each of the notches on Y-axis
        t.forward(25)
        t.write(numsY)
        t.back(25)
        t.down()
        t.right(90)
        numsY += 7
    #Draw label Y
    t.up()
    t.goto((-startpos - 75), -(scale/startpos - 50))
    t.write("Index")

def plotGraph(x, y, size, startpos, notch):
    #Set our pen at the origin
    t.up()
    t.goto(x[0] - notch, y[0])
    t.down()
    for i in range(len(x)):
        #Logic for making sure the line is the right color. If the previous point is smaller than the current point or if it is the first point on the graph the line will be green.
        if y[i - 1] < y[i] or y[i] == y[0]:
            t.pencolor("green")
        else:
            t.pencolor("red")
        #Graph, subtract from X to make sure that the notch offset is correct.
        t.goto(x[i], y[i])
        print(x[i],y[i])
    
#-----Parameter Zone-----#
location = 250
scale = 3
notchWidth = 20
days = []
index = []
t = turtle.Pen()
t.speed(0)
t.width(3)


with open("S:\CS 121\stockIndex.csv", "r") as csvfile:
    csvreader = csv.reader(csvfile)
    #Extracting each data row one by one, I make sure to transform the data to fit the scale of the graph.
    for row in csvreader:
        row[0] = (int(row[0]) * notchWidth) - location
        row[1] = (int(row[1]) * scale) - location
        days.append(row[0])
        index.append(row[1])
#Function calls wherein we pass our preset paramaters, which makes for easy customization.
drawGraph(days, index, scale, location, notchWidth)
plotGraph(days, index, scale, location, notchWidth)
input()
