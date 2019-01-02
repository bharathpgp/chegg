from graphics import *
from time import sleep


def bounce(gold_point, dx, dy):  # Function 'bounces' ball off wall
    center = gold_point.getCenter()  # get center of ball
    if center.getX() not in range(10, 290):  # within window?
        dx *= -1  # change direction
    if center.getY() not in range(10, 290):
        dy *= -1
    return dx, dy  # return new values


def main():
    window = GraphWin("Win", 300, 300)
    radius = 15
    gold_point = Circle(Point(150, 150), radius)  # make ball
    gold_point.setFill('gold')
    gold_point.draw(window)
    dx, dy = 3, -5

    # initial direction
    while not window.checkMouse():  # repeat until mouse click
        gold_point.move(dx, dy)  # move ball
        # there is no direct way to change the radius of the circle, so we need to
        # undraw the current object, re initialize the object with reduced radius,
        # and draw it again

        # getting center of current ball
        center = gold_point.getCenter()
        # undrawing old ball
        gold_point.undraw()
        # creating new ball with above center coordinates and with reduced radius
        gold_point = Circle(center, radius)
        gold_point.setFill('gold')
        # drawing it again
        gold_point.draw(window)
        # reducing the radius by 0.05 for the next iteration
        radius -= 0.05
        # preventing radius being zero or negative
        if radius <= 0:
            radius = 0.05
        sleep(0.02)  # sleep 0.02 seconds
        dx, dy = bounce(gold_point, dx, dy)
        # call function to check
    window.getMouse()
    window.close()  # close windows


main()
