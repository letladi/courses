from plotting import plot
#
# L = [[2,2], [3,2], [1.75,1], [2,1], [2.25, 1], [2.5,1], [2.75,1], [3,1], [3.25,1]]
#
# def add(v, w = [1, 2]): return [v[0] + v[0], v[1] + w[1]]
#
# def addn(v, w): return [x+y for (x,y) in zip(v, w)]

def segment(pt1, pt2, pointsBetween = 100.0):
    diffX = pt2[0] - pt1[0]
    diffY = pt2[1] - pt1[1]

    xIncr = (diffX / pointsBetween)
    yIncr = (diffY / pointsBetween)
    list = [None]*int(pointsBetween)
    list[0] = pt1

    for x in range(1, int(pointsBetween)):
        y = x - 1
        list[x] = [list[y][0] + xIncr, list[y][1] + yIncr]

    return list


plot(segment([3.5, 3], [0.5, 1]))
