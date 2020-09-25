from graphics import *
from time import sleep

def bounce(gold_point, dx, dy):
    # Function 'bounces' ball off wall
    
    center = gold_point.getCenter()
    # Get the center of the ball
    
    if center.getX() not in range(10, 290):
        # Is the center within the window?
        dx *= -1        # Changes the direction
        
    if center.getY() not in range(10, 290):
        dy *= -1
    return dx, dy

def main():
    window = GraphWin("Win", 300, 300)
    radius = 15
    gold_point = Circle(Point(150, 150), radius)  # Make ball
    gold_point.setFill('gold')
    gold_point.draw(window)
    dx, dy = 3, -5      # Initial direction
    while not window.checkMouse():  # repeat until mouse click
        gold_point.move(dx, dy)
        """ Move the ball.
        There is no direct way to change the radius of the circle, so we need to remove
        the current object, and re-initialize the object with reduced radius,
        and draw it again."""
        
        center = gold_point.getCenter()
        # Getting the center of current ball

        gold_point.undraw()
        # Removing the old ball
        
        gold_point = Circle(center, radius)
        # Creating new ball with above center coordinates and with reduced radius
        
        gold_point.setFill('gold')
        
        gold_point.draw(window)
        # Re-drawing the ball
        
        radius -= 0.05
        # Reducing the radius by 0.05 for the next iteration
        
        if radius <= 0:
            # Preventing radius being zero or negative
            radius = 0.05
        
        sleep(0.02)     # Sleep 0.02 seconds
        
        dx, dy = bounce(gold_point, dx, dy)
        # Call function to check
        
    window.getMouse()
    window.close()  # Close the Window

main()
