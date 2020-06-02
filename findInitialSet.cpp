#include "common.h"

/**
 * �⺻������ 11���� �񱳸� �ؼ� ��¥ ��¥�� ���������� ��� Ž���ϴ� ����
 * 0�� ~ 10�� (11��) ���ο� ��¥ ��¥�� �����ִٸ�
*/
// unknown�� ������ 100���� �����ϰ� �����. �ٸ����� ������� ����!
knownSet findInitialSet(vector<int> unknown) {
    int ptr = 0, loop = 0;
    vector<int> unknowns[10];
    knownSet output;


    for (int i = 0; i < 11; i++) unknowns[loop].push_back(unknown.at(ptr++));
    knownSet result = find(unknowns[loop]);
    if (result.unknown.size() == 0) {
        output.real.insert(output.real.end(), result.real.begin(), result.real.end());
        output.fake.insert(output.fake.end(), result.fake.begin(), result.fake.end());
        while (ptr < 100) output.unknown.push_back(unknown.at(ptr++));
        return output;
    }

    while (output.real.size() == 0 && output.fake.size() == 0) {
        loop += 1;
        if (loop == 9) { // Last one is special one
            int a[] = { 0, -1 };
            int b[] = { 99, -1 };
            int r = balance(a, b);
            switch (r)
            {
            case LARGE:
                for (int i = 0; i < loop; i++)output.real.insert(output.real.end(), unknowns[i].begin(), unknowns[i].end());
                output.fake.push_back(99);
                break;
            case EQUAL:
                exit(-1); // IMPOSSIBLE CASE
                break;
            case SMALL:
                for (int i = 0; i < loop; i++)output.fake.insert(output.fake.end(), unknowns[i].begin(), unknowns[i].end());
                output.real.push_back(99);
                break;
            }
            return output;
        }
        for (int i = 0; i < 11; i++) unknowns[loop].push_back(unknown.at(ptr++));
        int r = balanceWithVector(unknowns[0], unknowns[loop]);
        switch (r)
        {
        case LARGE:
            for (int i = 0; i < loop; i++)output.real.insert(output.real.end(), unknowns[i].begin(), unknowns[i].end());
            break;
        case EQUAL:
            break;
        case SMALL:
            for (int i = 0; i < loop; i++)output.fake.insert(output.fake.end(), unknowns[i].begin(), unknowns[i].end());
            break;
        }
    }
    result = find(unknowns[loop]);
    output.real.insert(output.real.end(), result.real.begin(), result.real.end());
    output.fake.insert(output.fake.end(), result.fake.begin(), result.fake.end());
    while (ptr < 100) output.unknown.push_back(unknown.at(ptr++));
    return output;
}
