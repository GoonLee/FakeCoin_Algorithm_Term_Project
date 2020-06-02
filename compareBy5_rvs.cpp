#include "common.h"

//���� ����ü�� fake 4���� real 1���� �ִٰ� ������.
knownSet compareBy5_rvs(vector<int> real, vector<int> fake, vector<int> unknown)
{
    int flag = 0; //5�� ���ߴ��� 4�� ���ߴ��� üũ
    int fakeIdx1 = fake[0]; int fakeIdx2 = fake[1]; int fakeIdx3 = fake[2];
    int fakeIdx4 = fake[3]; int realIdx = real[0];
    knownSet output;
    int right[] = { fakeIdx1,fakeIdx2,fakeIdx3,fakeIdx4,realIdx,-1 };

    int left[] = { unknown[0],unknown[1],unknown[2],unknown[3],unknown[4],-1 };

    switch (balance(left, right))
    {
    case SMALL:
    {
        for (int i = 0; i < 5; i++)
            fake.push_back(unknown[i]);
        break;
    }
    case EQUAL: //f4 r1
    {
        int left[] = { unknown[0],-1 }; int right[] = { unknown[1],-1 };
        switch (balance(left, right))
        {
        case LARGE:
        {
            real.push_back(unknown[0]);
            fake.push_back(unknown[1]);
            fake.push_back(unknown[2]);
            fake.push_back(unknown[3]);
            fake.push_back(unknown[4]);
            break;
        }
        case SMALL:
        {
            real.push_back(unknown[1]);
            fake.push_back(unknown[0]);
            fake.push_back(unknown[2]);
            fake.push_back(unknown[3]);
            fake.push_back(unknown[4]);
            break;
        }
        case EQUAL:
        {
            int left[] = { unknown[2],-1 }; int right[] = { unknown[3],-1 };
            switch (balance(left, right))
            {
            case LARGE:
            {
                real.push_back(unknown[2]);
                fake.push_back(unknown[0]);
                fake.push_back(unknown[1]);
                fake.push_back(unknown[3]);
                fake.push_back(unknown[4]);
                break;
            }
            case SMALL:
            {
                real.push_back(unknown[3]);
                fake.push_back(unknown[0]);
                fake.push_back(unknown[1]);
                fake.push_back(unknown[2]);
                fake.push_back(unknown[4]);
                break;
            }
            case EQUAL:
            {
                real.push_back(unknown[4]);
                fake.push_back(unknown[0]);
                fake.push_back(unknown[1]);
                fake.push_back(unknown[2]);
                fake.push_back(unknown[3]);
                break;
            }
            }
            break;
        }
        }
        break;
    }
    case LARGE:
    {
        int arrCase[2] = { 0,0 }; //�տ� 2�� ���� ����� �ڿ� 2�� ���� ��� ����
        int left[] = { unknown[0],-1 }; int right[] = { unknown[1],-1 };
        switch (balance(left, right))
        {
        case LARGE:
        {
            arrCase[0] = 1; //0 real 1 fake
            break;
        }
        case SMALL:
        {
            arrCase[0] = -1; //0 fake 1 real
            break;
        }
        case EQUAL:
        {
            arrCase[0] = 0;
            break;
        }
        }
        int left1[] = { unknown[2],-1 }; int right1[] = { unknown[3],-1 };
        switch (balance(left1, right1))
        {
        case LARGE:
        {
            arrCase[1] = 1; //2 real 3 fake
            break;
        }
        case SMALL:
        {
            arrCase[1] = -1; //2 fake 3 real
            break;
        }
        case EQUAL:
        {
            arrCase[1] = 0;
            break;
        }
        }
        //2�� �� ��
        if (arrCase[0] == 1)
        {
            if (arrCase[1] == 1)
            {
                real.push_back(unknown[0]); real.push_back(unknown[2]);
                fake.push_back(unknown[1]); fake.push_back(unknown[3]);
                flag = -1;
            }
            else if (arrCase[1] == -1)
            {
                real.push_back(unknown[0]); real.push_back(unknown[3]);
                fake.push_back(unknown[1]); fake.push_back(unknown[2]);
                flag = -1;
            }
            else
            {
                //���� unknown[0]: real, unknown[1]: fake
                int left[] = { unknown[3],-1 }; int right[] = { unknown[4],-1 };
                switch (balance(left, right))
                {
                case LARGE:
                {
                    real.push_back(unknown[0]); real.push_back(unknown[2]); real.push_back(unknown[3]);
                    fake.push_back(unknown[1]); fake.push_back(unknown[4]);
                    break;
                }
                case SMALL:
                {
                    real.push_back(unknown[0]); real.push_back(unknown[4]);
                    fake.push_back(unknown[1]); fake.push_back(unknown[2]); fake.push_back(unknown[3]);
                    break;
                }
                case EQUAL:
                {
                    real.push_back(unknown[0]); real.push_back(unknown[2]); real.push_back(unknown[3]); real.push_back(unknown[4]);
                    fake.push_back(unknown[1]);
                    break;
                }
                }
            }
        }
        else if (arrCase[0] == -1)
        {
            if (arrCase[1] == 1)
            {
                real.push_back(unknown[1]); real.push_back(unknown[2]);
                fake.push_back(unknown[0]); fake.push_back(unknown[3]);
                flag = -1;
            }
            else if (arrCase[1] == -1)
            {
                real.push_back(unknown[1]); real.push_back(unknown[3]);
                fake.push_back(unknown[0]); fake.push_back(unknown[2]);
                flag = -1;
            }
            else
            {
                //���� ptr: fake, ptr+1: real
                int left[] = { unknown[3],-1 }; int right[] = { unknown[4],-1 };
                switch (balance(left, right))
                {
                case LARGE:
                {
                    real.push_back(unknown[1]); real.push_back(unknown[2]); real.push_back(unknown[3]);
                    fake.push_back(unknown[0]); fake.push_back(unknown[4]);
                    break;
                }
                case SMALL:
                {
                    real.push_back(unknown[1]); real.push_back(unknown[4]);
                    fake.push_back(unknown[0]); fake.push_back(unknown[2]); fake.push_back(unknown[3]);
                    break;
                }
                case EQUAL:
                {
                    real.push_back(unknown[1]); real.push_back(unknown[2]); real.push_back(unknown[3]); real.push_back(unknown[4]);
                    fake.push_back(unknown[0]);
                    break;
                }
                }
            }
        }
        else
        {
            if (arrCase[1] == 1)
            {
                //���� ptr+2: real, ptr+3: fake
                int left[] = { unknown[0],-1 }; int right[] = { unknown[4],-1 };
                switch (balance(left, right))
                {
                case LARGE:
                {
                    real.push_back(unknown[0]); real.push_back(unknown[1]); real.push_back(unknown[2]);
                    fake.push_back(unknown[3]); fake.push_back(unknown[4]);
                    break;
                }
                case SMALL:
                {
                    real.push_back(unknown[2]); real.push_back(unknown[4]);
                    fake.push_back(unknown[0]); fake.push_back(unknown[1]); fake.push_back(unknown[3]);
                    break;
                }
                case EQUAL:
                {
                    real.push_back(unknown[0]); real.push_back(unknown[1]); real.push_back(unknown[2]); real.push_back(unknown[4]);
                    fake.push_back(unknown[3]);
                    break;
                }
                }
            }
            else if (arrCase[1] == -1)
            {
                //���� unknown[2]: fake, unknown[3]: real
                int left[] = { unknown[0],-1 }; int right[] = { unknown[4],-1 };
                switch (balance(left, right))
                {
                case LARGE:
                {
                    real.push_back(unknown[0]); real.push_back(unknown[1]); real.push_back(unknown[3]);
                    fake.push_back(unknown[2]); fake.push_back(unknown[4]);
                    break;
                }
                case SMALL:
                {
                    real.push_back(unknown[3]); real.push_back(unknown[4]);
                    fake.push_back(unknown[0]); fake.push_back(unknown[1]); fake.push_back(unknown[2]);
                    break;
                }
                case EQUAL:
                {
                    real.push_back(unknown[0]); real.push_back(unknown[1]); real.push_back(unknown[3]); real.push_back(unknown[4]);
                    fake.push_back(unknown[2]);
                    break;
                }
                }
            }
            else
            {
                //unknown[0],unknown[1] �� ���� unknown[2],unknown[3] �� ���� ��Ȳ
                int left[] = { unknown[0],-1 }; int right[] = { unknown[2],-1 };
                switch (balance(left, right))
                {
                case LARGE:
                {
                    real.push_back(unknown[0]); real.push_back(unknown[1]);
                    fake.push_back(unknown[2]); fake.push_back(unknown[3]);
                    flag = -1;
                    break;
                }
                case SMALL:
                {
                    real.push_back(unknown[2]); real.push_back(unknown[3]);
                    fake.push_back(unknown[0]); fake.push_back(unknown[1]);
                    flag = -1;
                    break;
                }
                case EQUAL:
                {
                    real.push_back(unknown[0]); real.push_back(unknown[1]); real.push_back(unknown[2]); real.push_back(unknown[3]);
                    flag = -1; //unknown[4]�� 1�� ���ϱ� �Ʊ��Ƿ� pass �Ѵ�.
                    break;
                }
                }
            }
        }
    }
    }
    if (flag == -1)
    {
        for (int i = 0; i < 4; i++) //4�� ã������ unknown���� 4�� ����
            unknown.erase(unknown.begin());
    }
    else if (flag == 0)
    {
        for (int i = 0; i < 5; i++) //5�� ã������ unknown���� 5�� ����
            unknown.erase(unknown.begin());
    }
    output.real = real; output.fake = fake; output.unknown = unknown;
    return output;
}