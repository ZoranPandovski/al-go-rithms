#include <stdio.h>
#include <string.h>
 
enum HouseStatus { Invalid, Underfull, Valid };
 
enum Attrib { C, M, D, A, S };
 
// Unfilled attributes are represented by -1
enum Colors { Red, Green, White, Yellow, Blue };
enum Mans { English, Swede, Dane, German, Norwegian };
enum Drinks { Tea, Coffee, Milk, Beer, Water };
enum Animals { Dog, Birds, Cats, Horse, Fish };
enum Smokes { PallMall, Dunhill, Blend, BlueMaster, Prince };
 
 
void printHouses(int ha[5][5]) {
    const char *color[] =  { "Red", "Green", "White", "Yellow", "Blue" };
    const char *man[] =    { "English", "Swede", "Dane", "German", "Norwegian" };
    const char *drink[] =  { "Tea", "Coffee", "Milk", "Beer", "Water" };
    const char *animal[] = { "Dog", "Birds", "Cats", "Horse", "Fish" };
    const char *smoke[] =  { "PallMall", "Dunhill", "Blend", "BlueMaster", "Prince" };
 
    printf("%-10.10s%-10.10s%-10.10s%-10.10s%-10.10s%-10.10s\n",
           "House", "Color", "Man", "Drink", "Animal", "Smoke");
 
    for (int i = 0; i < 5; i++) {
        printf("%-10d", i);
        if (ha[i][C] >= 0)
            printf("%-10.10s", color[ha[i][C]]);
        else
            printf("%-10.10s", "-");
        if (ha[i][M] >= 0)
            printf("%-10.10s", man[ha[i][M]]);
        else
            printf("%-10.10s", "-");
        if (ha[i][D] >= 0)
            printf("%-10.10s", drink[ha[i][D]]);
        else
            printf("%-10.10s", "-");
        if (ha[i][A] >= 0)
            printf("%-10.10s", animal[ha[i][A]]);
        else
            printf("%-10.10s", "-");
        if (ha[i][S] >= 0)
            printf("%-10.10s\n", smoke[ha[i][S]]);
        else
            printf("-\n");
    }
}
 
 
int checkHouses(int ha[5][5]) {
    int c_add = 0, c_or = 0;
    int m_add = 0, m_or = 0;
    int d_add = 0, d_or = 0;
    int a_add = 0, a_or = 0;
    int s_add = 0, s_or = 0;
 
    // Cond 9: In the middle house they drink milk.
    if (ha[2][D] >= 0 && ha[2][D] != Milk)
        return Invalid;
 
    // Cond 10: The Norwegian lives in the first house.
    if (ha[0][M] >= 0 && ha[0][M] != Norwegian)
        return Invalid;
 
    for (int i = 0; i < 5; i++) {
        // Uniqueness tests.
        if (ha[i][C] >= 0) {
            c_add += (1 << ha[i][C]);
            c_or |= (1 << ha[i][C]);
        }
        if (ha[i][M] >= 0) {
            m_add += (1 << ha[i][M]);
            m_or |= (1 << ha[i][M]);
        }
        if (ha[i][D] >= 0) {
            d_add += (1 << ha[i][D]);
            d_or |= (1 << ha[i][D]);
        }
        if (ha[i][A] >= 0) {
            a_add += (1 << ha[i][A]);
            a_or |= (1 << ha[i][A]);
        }
        if (ha[i][S] >= 0) {
            s_add += (1 << ha[i][S]);
            s_or |= (1 << ha[i][S]);
        }
 
        // Cond 2: The English man lives in the red house.
        if ((ha[i][M] >= 0 && ha[i][C] >= 0) &&
            ((ha[i][M] == English && ha[i][C] != Red) || // Checking both
             (ha[i][M] != English && ha[i][C] == Red)))  // to make things quicker.
            return Invalid;
 
        // Cond 3: The Swede has a dog.
        if ((ha[i][M] >= 0 && ha[i][A] >= 0) &&
            ((ha[i][M] == Swede && ha[i][A] != Dog) ||
             (ha[i][M] != Swede && ha[i][A] == Dog)))
            return Invalid;
 
        // Cond 4: The Dane drinks tea.
        if ((ha[i][M] >= 0 && ha[i][D] >= 0) &&
            ((ha[i][M] == Dane && ha[i][D] != Tea) ||
             (ha[i][M] != Dane && ha[i][D] == Tea)))
            return Invalid;
 
        // Cond 5: The green house is immediately to the left of the white house.
        if ((i > 0 && ha[i][C] >= 0 /*&& ha[i-1][C] >= 0 */ ) &&
            ((ha[i - 1][C] == Green && ha[i][C] != White) ||
             (ha[i - 1][C] != Green && ha[i][C] == White)))
            return Invalid;
 
        // Cond 6: drink coffee in the green house.
        if ((ha[i][C] >= 0 && ha[i][D] >= 0) &&
            ((ha[i][C] == Green && ha[i][D] != Coffee) ||
             (ha[i][C] != Green && ha[i][D] == Coffee)))
            return Invalid;
 
        // Cond 7: The man who smokes Pall Mall has birds.
        if ((ha[i][S] >= 0 && ha[i][A] >= 0) &&
            ((ha[i][S] == PallMall && ha[i][A] != Birds) ||
             (ha[i][S] != PallMall && ha[i][A] == Birds)))
            return Invalid;
 
        // Cond 8: In the yellow house they smoke Dunhill.
        if ((ha[i][S] >= 0 && ha[i][C] >= 0) &&
            ((ha[i][S] == Dunhill && ha[i][C] != Yellow) ||
             (ha[i][S] != Dunhill && ha[i][C] == Yellow)))
            return Invalid;
 
        // Cond 11: The man who smokes Blend lives in the house next to the house with cats.
        if (ha[i][S] == Blend) {
            if (i == 0 && ha[i + 1][A] >= 0 && ha[i + 1][A] != Cats)
                return Invalid;
            else if (i == 4 && ha[i - 1][A] != Cats)
                return Invalid;
            else if (ha[i + 1][A] >= 0 && ha[i + 1][A] != Cats && ha[i - 1][A] != Cats)
                return Invalid;
        }
 
        // Cond 12: In a house next to the house where they have a horse, they smoke Dunhill.
        if (ha[i][S] == Dunhill) {
            if (i == 0 && ha[i + 1][A] >= 0 && ha[i + 1][A] != Horse)
                return Invalid;
            else if (i == 4 && ha[i - 1][A] != Horse)
                return Invalid;
            else if (ha[i + 1][A] >= 0 && ha[i + 1][A] != Horse && ha[i - 1][A] != Horse)
                return Invalid;
        }
 
        // Cond 13: The man who smokes Blue Master drinks beer.
        if ((ha[i][S] >= 0 && ha[i][D] >= 0) &&
            ((ha[i][S] == BlueMaster && ha[i][D] != Beer) ||
             (ha[i][S] != BlueMaster && ha[i][D] == Beer)))
            return Invalid;
 
        // Cond 14: The German smokes Prince
        if ((ha[i][M] >= 0 && ha[i][S] >= 0) &&
            ((ha[i][M] == German && ha[i][S] != Prince) ||
             (ha[i][M] != German && ha[i][S] == Prince)))
            return Invalid;
 
        // Cond 15: The Norwegian lives next to the blue house.
        if (ha[i][M] == Norwegian &&
            ((i < 4 && ha[i + 1][C] >= 0 && ha[i + 1][C] != Blue) ||
             (i > 0 && ha[i - 1][C] != Blue)))
            return Invalid;
 
        // Cond 16: They drink water in a house next to the house where they smoke Blend.
        if (ha[i][S] == Blend) {
            if (i == 0 && ha[i + 1][D] >= 0 && ha[i + 1][D] != Water)
                return Invalid;
            else if (i == 4 && ha[i - 1][D] != Water)
                return Invalid;
            else if (ha[i + 1][D] >= 0 && ha[i + 1][D] != Water && ha[i - 1][D] != Water)
                return Invalid;
        }
 
    }
 
    if ((c_add != c_or) || (m_add != m_or) || (d_add != d_or)
        || (a_add != a_or) || (s_add != s_or)) {
        return Invalid;
    }
 
    if ((c_add != 0b11111) || (m_add != 0b11111) || (d_add != 0b11111)
        || (a_add != 0b11111) || (s_add != 0b11111)) {
        return Underfull;
    }
 
    return Valid;
}
 
 
int bruteFill(int ha[5][5], int hno, int attr) {
    int stat = checkHouses(ha);
    if ((stat == Valid) || (stat == Invalid))
        return stat;
 
    int hb[5][5];
    memcpy(hb, ha, sizeof(int) * 5 * 5);
    for (int i = 0; i < 5; i++) {
        hb[hno][attr] = i;
        stat = checkHouses(hb);
        if (stat != Invalid) {
            int nexthno, nextattr;
            if (attr < 4) {
                nextattr = attr + 1;
                nexthno = hno;
            } else {
                nextattr = 0;
                nexthno = hno + 1;
            }
 
            stat = bruteFill(hb, nexthno, nextattr);
            if (stat != Invalid) {
                memcpy(ha, hb, sizeof(int) * 5 * 5);
                return stat;
            }
        }
    }
 
    // We only come here if none of the attr values assigned were valid.
    return Invalid;
}
 
 
int main() {
    int ha[5][5] = {{-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1},
                    {-1, -1, -1, -1, -1}};
 
    bruteFill(ha, 0, 0);
    printHouses(ha);
 
    return 0;
}