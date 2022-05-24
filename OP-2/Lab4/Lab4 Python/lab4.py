from point import pointX, pointXY

k = int(input("Input k: "))
n = int(input("Input n: "))
t = float(input("Input t: "))

coords = []
distances = []
xpo = []
xypo = []

for i in range(k):
    obj = pointX(t)
    xpo.append(obj)
    print(obj)
    for j in range(i):
        dist = obj.get_distance(xpo[j].get_x(), xpo[j].get_y())
        coordinates = [obj.get_x(), obj.get_y(), xpo[j].get_x(), xpo[j].get_y()]
        coords.append(coordinates)
        distances.append(dist)

for i in range(n):
    obj = pointXY(t)
    xypo.append(obj)
    print(obj)
    for j in range(i):
        dist = obj.get_distance(xypo[j].get_x(), xypo[j].get_y())
        coordinates = [obj.get_x(), obj.get_y(), xypo[j].get_x(), xypo[j].get_y()]
        coords.append(coordinates)
        distances.append(dist)

for i in range(k):
    for j in range(n):
        dist = xpo[i].get_distance(xypo[j].get_x(), xypo[j].get_y())
        coordinates = [xpo[i].get_x(), xpo[i].get_y(), xypo[j].get_x(), xypo[j].get_y()]
        coords.append(coordinates)
        distances.append(dist)

count = distances.index(max(distances))
print(f'Max distance: {distances[count]}')
print(f'Between points with coordinates: ({coords[count][0]}; {coords[count][1]}), ({coords[count][2]}; {coords[count][3]})')