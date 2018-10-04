#!/usr/bin/python
# -*- coding: utf-8 -*-
# row = [hour, temperature, relHumidity, [cloudCover, cloudHeight], [windSpdLow, windSpdHigh]]


def isTempUnder(row, temp):
    return row[1] < temp


def isHumidityOver(row, percent):
    return row[2] > percent


def isCloudHeightUnder(row, height):
    (cloudCover, cloudHeight) = row[3]
    return cloudHeight < height


def snowChance(data):
    totRows = len(data)
    snowCnt = 0.0
    hours = []
    for row in data:
        row0, temperature, relHumidity, cloud, row4 = row
        if relHumidity > 0.8 and \
            temperature < 0.5 and \
            cloud[1] < 1000:
            snowCnt += 1
            hours.append(row0)
    hours.sort()
    chance = snowCnt / totRows
    time = 0 if snowCnt == 0 else hours[-1] - hours[0]
    return [chance, time]


data = [
    [0, 1.5, 0.4, [0.3, 42], [5.1, 10.0]],
    [10, 1.4, 0.3, [0.2, 41], [6.2, 8.6]],
    [3, -5.1, 0.91, [0.83, 21], [107.1, 108.1]],
    [12, -6.3, 0.94, [0.91, 30], [106.5, 109.4]],
    [18, 20.5, 0.4, [0.3, 12000], [60.1, 162.4]],
    [2, 20.4, 0.3, [0.2, 11000], [105.6, 118.7]],
    [5, -9.2, 0.2, [0.93, 1001], [6.2, 6.3]],
    [15, -2.4, 0.1, [0.95, 1981], [7.4, 8.5]],
    ]

if __name__ == '__main__':
    print(isTempUnder(data[1], 1.4))
    print(isHumidityOver(data[1], 0.3))
    print(isCloudHeightUnder(data[1], 42))
    print(snowChance(data))
