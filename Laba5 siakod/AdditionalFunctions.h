#pragma once

//Возвращает сумму кодировок символов в строке
int GetStrSum(string str) {
    int sum = 0;
    for (char c : str) {
        sum += static_cast<int>(c);
    }
    return sum;
}


ostream& operator << (ostream& os, const Date& d) {
    return os << d.dd << '.' << d.mm << '.' << d.yy;
}


ostream& operator << (ostream& os, const Employee& e) {
    return os << e.prof << ' ' << e.period;
}