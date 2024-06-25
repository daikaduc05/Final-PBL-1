import pandas as pd
import matplotlib.pyplot as plt


file_path = input("Nhập đường dẫn tới file CSV chứa dữ liệu : ")

try:
    with open(file_path, 'r') as f:
        first_line = f.readline().strip()
        first_line = f.readline().strip()
        if ';' in first_line:
            df = pd.read_csv(file_path, delimiter=';', skiprows=1)
            column_names = first_line.split(';')
        else:
            print("Không hợp lệ")
            exit()
except FileNotFoundError:
    print("Không hợp lệ")

coefficients_path = 'coefficients.csv'
try:
    with open(coefficients_path, 'r') as f:
        lines = f.readlines()
        if len(lines) < 2:
            print("File coefficients.csv không đủ dữ liệu")
            exit()
        intercept = float(lines[0].strip())
        slope = float(lines[1].strip())
except FileNotFoundError:
    print(f"Không tìm thấy file {coefficients_path}")
    exit()

df[column_names[0]] = pd.to_numeric(df[column_names[0]], errors='coerce')
df[column_names[1]] = pd.to_numeric(df[column_names[1]], errors='coerce')
df = df.dropna()

x = df[column_names[0]]
y = df[column_names[1]]

plt.scatter(x, y, color='blue', label='Dữ liệu thực tế')
plt.plot(x, intercept + slope*x, color='red', label='Đường hồi quy tuyến tính')

plt.xlabel(column_names[0])
plt.ylabel(column_names[1])
plt.title('Hồi quy tuyến tính của {} so với {}'.format(column_names[1], column_names[0]))

plt.legend()

plt.show()
