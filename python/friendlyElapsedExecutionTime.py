# Requested by project waste not inc.
#
# Problem 1 (Python)
#
# Provide some Python code that can be used to measure how long a function takes to run in a friendly
# format. The amount of time can range from less than a second to several hours and should be easy
# for a human to read (for example “00:00:00:00012” is not a good output).


import time

start = time.time()
i = 0
while i < 150000:
    i = i + 1
end = time.time()

def formatElapsedTime(seconds):
    timeUnits = [
        365*24*60*60,
        7*24*60*60,
        24*60*60,
        60*60,
        60,
        1,
    ]

    results = []

    for timeUnit in timeUnits:
        result = seconds / timeUnit
        # print("result", result, seconds)
        if float(result) >= 1 :
            if(int(seconds) > 60):
                results.append(int(result))
            else:
                results.append(float(result))
            seconds = seconds - (timeUnit*int(result))
        elif len(results) > 0 :
            results.append(int(result))

    friendlyTimeMeasuresBase = [
        "Years",
        "Weeks",
        "Days",
        "Hours",
        "Minutes",
        "Seconds",
        ]

    sliceStart = len(friendlyTimeMeasuresBase)-len(results)
    sliceStart = sliceStart
    friendlyTimeMeasures = friendlyTimeMeasuresBase[sliceStart:len(friendlyTimeMeasuresBase)]

    formatted = "This took: "
    for index in range(0, len(results)):
        newline = '\n {0} {1}  '.format(results[index], friendlyTimeMeasures[index])
        formatted = formatted + newline

    return formatted;

testInput = 90061.1404271125793457
testInput = 694861.9404271125793457
# print(testInput % 1)

testOutput = formatElapsedTime(testInput)
print(testOutput)

# testInput2 = 70.1404271125793457
# testInput3 = 3722.1404271125793457
# testInput4 = 86800.1404271125793457
# testInput5 = 607800.1404271125793457

