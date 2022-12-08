from datetime import datetime

def calculate_leap_years(s, e):
    s = s.split()
    e = e.split()

    start_month = datetime.strptime(s[0], "%B").month
    end_month = datetime.strptime(e[0], "%B").month

    start_year = int(s[2])
    end_year = int(e[2])

    start_day = int(s[1][:-1])
    end_day = int(e[1][:-1])

    if start_month > 2:
        start_year += 1

    if (end_month < 2) or (end_month == 2 and end_day < 29):
        end_year -= 1

    if start_year > end_year:
        return 0

    leap_years = end_year // 4 - (start_year - 1) // 4
    leap_years += end_year // 400 - (start_year - 1) // 400
    leap_years -= end_year // 100 - (start_year - 1) // 100

    return leap_years


t = int(input())

for tc in range(1, t + 1):
    print(f'Case {tc}: ', end='')

    s = input()
    e = input()

    print(calculate_leap_years(s, e))
