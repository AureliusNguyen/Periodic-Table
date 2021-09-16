#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 120;
#ifdef _WIN32
#include <conio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif
struct Element
{
    char name[15];
    int atomicnum;
    double weight;
};
struct Element ElementArr[120];
void printMenu()
{
    printf("|====================================|\n");
    printf("|                                    |\n");
    printf("|         THE PERIODIC TABLE         |\n");
    printf("|                                    |\n");
    printf("|====================================|\n");
    printf("Choose an action:\n");
    printf("1/ Search an element's info by its atomic number\n");
    printf("2/ Search an element's info by its name\n");
    printf("3/ Print info about noble gases\n");
    printf("4/ Print info about halogens\n");
    printf("5/ Print info about hydrogen & alkali metals\n");
    printf("6/ Print info about alkaline earth metals\n");
    printf("7/ Search elements by their valence\n");
    printf("8/ Print info about all elements\n");
    printf("9/ Exit\n");
}
void PrintElementInfo(int a)
{
    printf("\n");
    printf("\tName\t");
    printf("\t\t  Atomic number\t");
    printf("\t\tAtomic mass\n");
    if (ElementArr[a].atomicnum == 10 || ElementArr[a].atomicnum == 26 || ElementArr[a].atomicnum == 30 || ElementArr[a].atomicnum == 50 || ElementArr[a].atomicnum == 79 || ElementArr[a].atomicnum == 82)
    {
        printf("\t%s   \t\t\t\t%d    \t\t\t    %.1lf\n\n", ElementArr[a].name, ElementArr[a].atomicnum, ElementArr[a].weight);
    }
    else if (ElementArr[a].atomicnum == 104)
    {
        printf("\t%s   \t\t%d    \t\t\t    %.1lf\n\n", ElementArr[a].name, ElementArr[a].atomicnum, ElementArr[a].weight);
    }
    else
    {
        printf("\t%s   \t    \t\t%d    \t\t\t    %.1lf\n\n", ElementArr[a].name, ElementArr[a].atomicnum, ElementArr[a].weight);
    }
}
void FindElementByAtomicNum()
{
    int a, c;
    do
    {
        printf("Type in an atomic number:\n");
        scanf("%d", &a);
        PrintElementInfo(a - 1);
        if (a < 0 || a > 118)
        {
            printf("Can't find the element with an atomic number of %d.\n", a);
            printf("Try again? 1/Yes| 0/No \n");
            scanf("%d", &c);
        }
    } while (c == 1);
}
void Valence()
{
    int valence;
    printf("Type in the valence of the elements (1-7):\n");
    scanf("%d", &valence);
    printf("Elements with the valence of %d:\n", valence);
    switch (valence)
    {
    case 1:
        printf("Hydrogen (H)\n");
        printf("Lithium (Li)\n");
        printf("Fluorine (F)\n");
        printf("Sodium (Na)\n");
        printf("Chlorine (Cl)\n");
        printf("Potassium (K)\n");
        printf("Copper (Cu)\n");
        printf("Bromine (Br)\n");
        printf("Silever (Ag)\n");
        printf("Mercury (Hg)\n");
        break;
    case 2:
        printf("Beryllium (Be)\n");
        printf("Carbon (Ca)\n");
        printf("Nitrogen (N)\n");
        printf("Oxygen (O)\n");
        printf("Magnesium (Mg)\n");
        printf("Sulfur (S)\n");
        printf("Calcium (Ca)\n");
        printf("Chromium (Cr)\n");
        printf("Manganese (Mn)\n");
        printf("Iron (Fe)\n");
        printf("Copper (Cu)\n");
        printf("Zinc (Zn)\n");
        printf("Barium (Ba)\n");
        printf("Mercury (Hg)\n");
        printf("Lead (Pb)\n");
        break;
    case 3:
        printf("Boron (B)\n");
        printf("Nitrogen (N)\n");
        printf("Aluminium (Al)\n");
        printf("Phosphorous (P)\n");
        printf("Chromium (Cr)\n");
        printf("Iron (Fe)\n");
        break;
    case 4:
        printf("Carbon (C)\n");
        printf("Nitrogen (N)\n");
        printf("Silicon (Si)\n");
        printf("Sulfur (S)\n");
        printf("Manganese (Mn)\n");
        printf("Lead (Pb)\n");
        break;
    case 5:
        printf("Nitrogen (N)\n");
        printf("Phosphorous (P)\n");
        break;
    case 6:
        printf("Sulfur (S)\n");
        break;
    case 7:
        printf("Manganese (Mn)\n");
    default:
        break;
    }
}
void FindElementByName()
{
    char str[15];
    int i = 0;
    int c;
    do
    {
        printf("Type in the name of the element: \n");
        fflush(stdin);
        gets(str);
        for (i; i < 118; i++)
        {
            if (strcmp(str, ElementArr[i].name) == 0)
            {
                PrintElementInfo(i);
                break;
            }
        }
        if (i > 118)
        {
            printf("Can't find the element %s.\n", str);
            printf("Try again? 1/Yes| 0/No \n");
            scanf("%d", &c);
        }
    } while (c == 1);
}
void NobleGases()
{
    PrintElementInfo(1);
    PrintElementInfo(9);
    PrintElementInfo(17);
    PrintElementInfo(35);
    PrintElementInfo(53);
    PrintElementInfo(85);
    PrintElementInfo(117);
}
void Halogens()
{
    PrintElementInfo(7);
    PrintElementInfo(16);
    PrintElementInfo(34);
    PrintElementInfo(52);
    PrintElementInfo(84);
    PrintElementInfo(116);
}
void Alkali()
{
    PrintElementInfo(0);
    PrintElementInfo(2);
    PrintElementInfo(10);
    PrintElementInfo(18);
    PrintElementInfo(36);
    PrintElementInfo(54);
    PrintElementInfo(86);
}
void AlkalineEarth()
{
    PrintElementInfo(3);
    PrintElementInfo(11);
    PrintElementInfo(19);
    PrintElementInfo(37);
    PrintElementInfo(55);
    PrintElementInfo(87);
}
void All()
{
    for (int i = 0; i < 118; i++)
    {
        PrintElementInfo(i);
    }
}
void MenuAction()
{
    int continue_status = 1;
    int b;
    do
    {
        clrscr();
        int a;
        printMenu();
        printf("\nYour action is: ");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            FindElementByAtomicNum();
            break;
        case 2:
            FindElementByName();
            break;
        case 3:
            NobleGases();
            break;
        case 4:
            Halogens();
            break;
        case 5:
            Alkali();
            break;
        case 6:
            AlkalineEarth();
            break;
        case 7:
            Valence();
            break;
        case 8:
            All();
            break;
        case 9:
            printf("Thank you for using our service. See you soon.\n");
            break;
        default:
            printf("An error has occurred, please choose an action again.\n");
            break;
        }
        printf("Continue? 1/Yes| 0/No: ");
        scanf("%d", &continue_status);
    } while (continue_status != 0);
}
int main()
{

    // DATABASE
    {
        // Hydrogen
        strcpy(ElementArr[0].name, "Hydrogen");
        ElementArr[0].atomicnum = 1;
        ElementArr[0].weight = 1;

        // Helium
        strcpy(ElementArr[1].name, "Helium");
        ElementArr[1].atomicnum = 2;
        ElementArr[1].weight = 4;

        // Lithium
        strcpy(ElementArr[2].name, "Lithium");
        ElementArr[2].atomicnum = 3;
        ElementArr[2].weight = 7;

        // Beryllium
        strcpy(ElementArr[3].name, "Beryllium");
        ElementArr[3].atomicnum = 4;
        ElementArr[3].weight = 9;

        // Boron
        strcpy(ElementArr[4].name, "Boron");
        ElementArr[4].atomicnum = 5;
        ElementArr[4].weight = 11;

        // Carbon
        strcpy(ElementArr[5].name, "Carbon");
        ElementArr[5].atomicnum = 6;
        ElementArr[5].weight = 12;

        // Nitrogen
        strcpy(ElementArr[6].name, "Nitrogen");
        ElementArr[6].atomicnum = 7;
        ElementArr[6].weight = 14;

        // Oxygen
        strcpy(ElementArr[7].name, "Oxygen");
        ElementArr[7].atomicnum = 8;
        ElementArr[7].weight = 16;

        // Fluorine
        strcpy(ElementArr[8].name, "Fluorine");
        ElementArr[8].atomicnum = 9;
        ElementArr[8].weight = 19;

        // Neon
        strcpy(ElementArr[9].name, "Neon");
        ElementArr[9].atomicnum = 10;
        ElementArr[9].weight = 20;

        // Sodium
        strcpy(ElementArr[10].name, "Sodium");
        ElementArr[10].atomicnum = 11;
        ElementArr[10].weight = 23;

        // Magnesium
        strcpy(ElementArr[11].name, "Magnesium");
        ElementArr[11].atomicnum = 12;
        ElementArr[11].weight = 24;

        // Aluminium
        strcpy(ElementArr[12].name, "Aluminium");
        ElementArr[12].atomicnum = 13;
        ElementArr[12].weight = 27;

        // Silicon
        strcpy(ElementArr[13].name, "Silicon");
        ElementArr[13].atomicnum = 14;
        ElementArr[13].weight = 28;

        // Phosphorus
        strcpy(ElementArr[14].name, "Phosphorus");
        ElementArr[14].atomicnum = 15;
        ElementArr[14].weight = 31;

        // Sulfur
        strcpy(ElementArr[15].name, "Sulfur");
        ElementArr[15].atomicnum = 16;
        ElementArr[15].weight = 32;

        // Chlorine
        strcpy(ElementArr[16].name, "Chlorine");
        ElementArr[16].atomicnum = 17;
        ElementArr[16].weight = 35.5;

        // Argon
        strcpy(ElementArr[17].name, "Argon");
        ElementArr[17].atomicnum = 18;
        ElementArr[17].weight = 40;

        // Potassium
        strcpy(ElementArr[18].name, "Potassium");
        ElementArr[18].atomicnum = 19;
        ElementArr[18].weight = 39;

        // Calcium
        strcpy(ElementArr[19].name, "Calcium");
        ElementArr[19].atomicnum = 20;
        ElementArr[19].weight = 40;

        // Scandium
        strcpy(ElementArr[20].name, "Scandium");
        ElementArr[20].atomicnum = 21;
        ElementArr[20].weight = 45;

        // Titanium
        strcpy(ElementArr[21].name, "Titanium");
        ElementArr[21].atomicnum = 22;
        ElementArr[21].weight = 48;

        // Vanadium
        strcpy(ElementArr[22].name, "Vanadium");
        ElementArr[22].atomicnum = 23;
        ElementArr[22].weight = 51;

        // Chromium
        strcpy(ElementArr[23].name, "Chromium");
        ElementArr[23].atomicnum = 24;
        ElementArr[23].weight = 52;

        // Manganese
        strcpy(ElementArr[24].name, "Manganese");
        ElementArr[24].atomicnum = 25;
        ElementArr[24].weight = 55;

        // Iron
        strcpy(ElementArr[25].name, "Iron");
        ElementArr[25].atomicnum = 26;
        ElementArr[25].weight = 56;

        // Cobalt
        strcpy(ElementArr[26].name, "Cobalt");
        ElementArr[26].atomicnum = 27;
        ElementArr[26].weight = 59;

        // Nickel
        strcpy(ElementArr[27].name, "Nickle");
        ElementArr[27].atomicnum = 28;
        ElementArr[27].weight = 59;

        // Copper
        strcpy(ElementArr[28].name, "Copper");
        ElementArr[28].atomicnum = 29;
        ElementArr[28].weight = 64;

        // Zinc
        strcpy(ElementArr[29].name, "Zinc");
        ElementArr[29].atomicnum = 30;
        ElementArr[29].weight = 65;

        // Galium
        strcpy(ElementArr[30].name, "Galium");
        ElementArr[30].atomicnum = 31;
        ElementArr[30].weight = 70;

        // Germanium
        strcpy(ElementArr[31].name, "Germanium");
        ElementArr[31].atomicnum = 32;
        ElementArr[31].weight = 73;

        // Arsenic
        strcpy(ElementArr[32].name, "Arsenic");
        ElementArr[32].atomicnum = 33;
        ElementArr[33].weight = 75;

        // Selenium
        strcpy(ElementArr[33].name, "Selenium");
        ElementArr[33].atomicnum = 34;
        ElementArr[33].weight = 79;

        // Bromine
        strcpy(ElementArr[34].name, "Bromine");
        ElementArr[34].atomicnum = 35;
        ElementArr[34].weight = 80;

        // Krypton
        strcpy(ElementArr[35].name, "Krypton");
        ElementArr[35].atomicnum = 36;
        ElementArr[35].weight = 84;

        // Rubidium
        strcpy(ElementArr[36].name, "Rubidium");
        ElementArr[36].atomicnum = 37;
        ElementArr[36].weight = 85.5;

        // Strontium
        strcpy(ElementArr[37].name, "Strontium");
        ElementArr[37].atomicnum = 38;
        ElementArr[37].weight = 88;

        // Yttrium
        strcpy(ElementArr[38].name, "Bromine");
        ElementArr[38].atomicnum = 39;
        ElementArr[38].weight = 89;

        // Zirconium
        strcpy(ElementArr[39].name, "Zirconium");
        ElementArr[39].atomicnum = 40;
        ElementArr[39].weight = 91;

        // Niobium
        strcpy(ElementArr[40].name, "Niobium");
        ElementArr[40].atomicnum = 41;
        ElementArr[40].weight = 93;

        // Molybdenum
        strcpy(ElementArr[41].name, "Molybdenum");
        ElementArr[41].atomicnum = 42;
        ElementArr[41].weight = 96;

        // Technetium
        strcpy(ElementArr[42].name, "Technetium");
        ElementArr[42].atomicnum = 43;
        ElementArr[42].weight = 97;

        // Ruthenium
        strcpy(ElementArr[43].name, "Ruthenium");
        ElementArr[43].atomicnum = 44;
        ElementArr[43].weight = 101;

        // Rhodium
        strcpy(ElementArr[44].name, "Rhodium");
        ElementArr[44].atomicnum = 45;
        ElementArr[44].weight = 103;

        // Palladium
        strcpy(ElementArr[45].name, "Palladium");
        ElementArr[45].atomicnum = 46;
        ElementArr[45].weight = 106;

        // Silver
        strcpy(ElementArr[46].name, "Silver");
        ElementArr[46].atomicnum = 47;
        ElementArr[46].weight = 108;

        // Cadmium
        strcpy(ElementArr[47].name, "Cadmium");
        ElementArr[47].atomicnum = 48;
        ElementArr[47].weight = 112;

        // Indium
        strcpy(ElementArr[48].name, "Indium");
        ElementArr[48].atomicnum = 49;
        ElementArr[48].weight = 115;

        // Tin
        strcpy(ElementArr[49].name, "Tin");
        ElementArr[49].atomicnum = 50;
        ElementArr[49].weight = 119;

        // Antimony
        strcpy(ElementArr[50].name, "Antimony");
        ElementArr[50].atomicnum = 51;
        ElementArr[50].weight = 122;

        // Tellurium
        strcpy(ElementArr[51].name, "Tellurium");
        ElementArr[51].atomicnum = 52;
        ElementArr[51].weight = 128;

        // Iodine
        strcpy(ElementArr[52].name, "Iodine");
        ElementArr[52].atomicnum = 53;
        ElementArr[52].weight = 127;

        // Xenon
        strcpy(ElementArr[53].name, "Xenon");
        ElementArr[53].atomicnum = 54;
        ElementArr[53].weight = 131;

        // Caesium
        strcpy(ElementArr[54].name, "Caesium");
        ElementArr[54].atomicnum = 55;
        ElementArr[54].weight = 133;

        // Barium
        strcpy(ElementArr[55].name, "Barium");
        ElementArr[55].atomicnum = 56;
        ElementArr[55].weight = 137;

        // Lanthanum
        strcpy(ElementArr[56].name, "Lanthanum");
        ElementArr[56].atomicnum = 57;
        ElementArr[56].weight = 139;

        // Cerium
        strcpy(ElementArr[57].name, "Cerium");
        ElementArr[57].atomicnum = 58;
        ElementArr[57].weight = 140;

        // Praseodymium
        strcpy(ElementArr[58].name, "Praseodymium");
        ElementArr[58].atomicnum = 59;
        ElementArr[58].weight = 141;

        // Neodymium
        strcpy(ElementArr[59].name, "Neodymium");
        ElementArr[59].atomicnum = 60;
        ElementArr[59].weight = 144;

        // Promethium
        strcpy(ElementArr[60].name, "Promethium");
        ElementArr[60].atomicnum = 61;
        ElementArr[60].weight = 145;

        // Samarium
        strcpy(ElementArr[61].name, "Samarium");
        ElementArr[61].atomicnum = 62;
        ElementArr[61].weight = 150;

        // Europium
        strcpy(ElementArr[62].name, "Europium");
        ElementArr[62].atomicnum = 63;
        ElementArr[62].weight = 152;

        // Gadolinium
        strcpy(ElementArr[63].name, "Gadolinium");
        ElementArr[63].atomicnum = 64;
        ElementArr[63].weight = 157;

        // Terbium
        strcpy(ElementArr[64].name, "Terbium");
        ElementArr[64].atomicnum = 65;
        ElementArr[64].weight = 159;

        // Dysprosium
        strcpy(ElementArr[65].name, "Dysprosium");
        ElementArr[65].atomicnum = 66;
        ElementArr[65].weight = 162;

        // Holmium
        strcpy(ElementArr[66].name, "Holmium");
        ElementArr[66].atomicnum = 67;
        ElementArr[66].weight = 165;

        // Erbium
        strcpy(ElementArr[67].name, "Erbium");
        ElementArr[67].atomicnum = 68;
        ElementArr[67].weight = 167;

        // Thulium
        strcpy(ElementArr[68].name, "Thulium");
        ElementArr[68].atomicnum = 69;
        ElementArr[68].weight = 169;

        // Ytterbium
        strcpy(ElementArr[69].name, "Ytterbium");
        ElementArr[69].atomicnum = 70;
        ElementArr[69].weight = 173;

        // Lutetium
        strcpy(ElementArr[70].name, "Lutetium");
        ElementArr[70].atomicnum = 71;
        ElementArr[70].weight = 175;

        // Hafnium
        strcpy(ElementArr[71].name, "Hafnium");
        ElementArr[71].atomicnum = 72;
        ElementArr[71].weight = 178.5;

        // Tantalum
        strcpy(ElementArr[72].name, "Tantalum");
        ElementArr[72].atomicnum = 73;
        ElementArr[72].weight = 181;

        // Tungsten
        strcpy(ElementArr[73].name, "Tungsten");
        ElementArr[73].atomicnum = 74;
        ElementArr[73].weight = 184;

        // Rhenium
        strcpy(ElementArr[74].name, "Rhenium");
        ElementArr[74].atomicnum = 75;
        ElementArr[74].weight = 186;

        // Osmium
        strcpy(ElementArr[75].name, "Osmium");
        ElementArr[75].atomicnum = 76;
        ElementArr[75].weight = 190;

        // Iridium
        strcpy(ElementArr[76].name, "Iridium");
        ElementArr[76].atomicnum = 77;
        ElementArr[76].weight = 192;

        // Platinum
        strcpy(ElementArr[77].name, "Platinum");
        ElementArr[77].atomicnum = 78;
        ElementArr[77].weight = 195;

        // Gold
        strcpy(ElementArr[78].name, "Gold");
        ElementArr[78].atomicnum = 79;
        ElementArr[78].weight = 197;

        // Mercury
        strcpy(ElementArr[79].name, "Mercury");
        ElementArr[79].atomicnum = 80;
        ElementArr[79].weight = 201;

        // Thallium
        strcpy(ElementArr[80].name, "Thallium");
        ElementArr[80].atomicnum = 81;
        ElementArr[80].weight = 2074;

        // Lead
        strcpy(ElementArr[81].name, "Lead");
        ElementArr[81].atomicnum = 82;
        ElementArr[81].weight = 207;

        // Bismuth
        strcpy(ElementArr[82].name, "Bismuth");
        ElementArr[82].atomicnum = 83;
        ElementArr[82].weight = 209;

        // Polonium
        strcpy(ElementArr[83].name, "Polonium");
        ElementArr[83].atomicnum = 84;
        ElementArr[83].weight = 209;

        // Astatine
        strcpy(ElementArr[84].name, "Astatine");
        ElementArr[84].atomicnum = 85;
        ElementArr[84].weight = 210;

        // Radon
        strcpy(ElementArr[85].name, "Radon");
        ElementArr[85].atomicnum = 86;
        ElementArr[85].weight = 222;

        // Francium
        strcpy(ElementArr[86].name, "Francium");
        ElementArr[86].atomicnum = 87;
        ElementArr[86].weight = 223;

        // Radium
        strcpy(ElementArr[87].name, "Radium");
        ElementArr[87].atomicnum = 88;
        ElementArr[87].weight = 226;

        // Actinium
        strcpy(ElementArr[88].name, "Actinium");
        ElementArr[88].atomicnum = 89;
        ElementArr[88].weight = 227;

        // Thorium
        strcpy(ElementArr[89].name, "Thorium");
        ElementArr[89].atomicnum = 90;
        ElementArr[89].weight = 232;

        // Protactinium
        strcpy(ElementArr[90].name, "Protactinium");
        ElementArr[90].atomicnum = 91;
        ElementArr[90].weight = 231;

        // Uranium
        strcpy(ElementArr[91].name, "Uranium");
        ElementArr[91].atomicnum = 92;
        ElementArr[91].weight = 238;

        // Neptunium
        strcpy(ElementArr[92].name, "Bismuth");
        ElementArr[92].atomicnum = 93;
        ElementArr[92].weight = 237;

        // Plutonium
        strcpy(ElementArr[93].name, "Plutonium");
        ElementArr[93].atomicnum = 94;
        ElementArr[93].weight = 244;

        // Americium
        strcpy(ElementArr[94].name, "Americium");
        ElementArr[94].atomicnum = 95;
        ElementArr[94].weight = 243;

        // Curium
        strcpy(ElementArr[95].name, "Curium");
        ElementArr[95].atomicnum = 96;
        ElementArr[95].weight = 247;

        // Berkelium
        strcpy(ElementArr[96].name, "Berkelium");
        ElementArr[96].atomicnum = 97;
        ElementArr[96].weight = 247;

        // Californium
        strcpy(ElementArr[97].name, "Californium");
        ElementArr[97].atomicnum = 98;
        ElementArr[97].weight = 251;

        // Einsteinium
        strcpy(ElementArr[98].name, "Einsteinium");
        ElementArr[98].atomicnum = 99;
        ElementArr[98].weight = 252;

        // Fermium
        strcpy(ElementArr[99].name, "Fermium");
        ElementArr[99].atomicnum = 100;
        ElementArr[99].weight = 257;

        // Mendelevium
        strcpy(ElementArr[100].name, "Mendelevium");
        ElementArr[100].atomicnum = 101;
        ElementArr[100].weight = 258;

        // Nobelium
        strcpy(ElementArr[101].name, "Nobelium");
        ElementArr[101].atomicnum = 102;
        ElementArr[101].weight = 259;

        // Lawrencium
        strcpy(ElementArr[102].name, "Lawrencium");
        ElementArr[102].atomicnum = 103;
        ElementArr[102].weight = 266;

        // Rutherfordium
        strcpy(ElementArr[103].name, "Rutherfordium");
        ElementArr[103].atomicnum = 104;
        ElementArr[103].weight = 267;

        // Dubnium
        strcpy(ElementArr[104].name, "Dubnium");
        ElementArr[104].atomicnum = 105;
        ElementArr[104].weight = 268;

        // Seaborgium
        strcpy(ElementArr[105].name, "Seaborgium");
        ElementArr[105].atomicnum = 106;
        ElementArr[105].weight = 269;

        // Bohrium
        strcpy(ElementArr[106].name, "Bohrium");
        ElementArr[106].atomicnum = 107;
        ElementArr[106].weight = 270;

        // Hassium
        strcpy(ElementArr[107].name, "Hassium");
        ElementArr[107].atomicnum = 108;
        ElementArr[107].weight = 269;

        // Meitnerium
        strcpy(ElementArr[108].name, "Meitnerium");
        ElementArr[108].atomicnum = 109;
        ElementArr[108].weight = 278;

        // Darmstadtium
        strcpy(ElementArr[109].name, "Darmstadium");
        ElementArr[109].atomicnum = 110;
        ElementArr[109].weight = 281;

        // Roentgenium
        strcpy(ElementArr[110].name, "Roentgenium");
        ElementArr[110].atomicnum = 111;
        ElementArr[110].weight = 282;

        // Copernicium
        strcpy(ElementArr[111].name, "Copernicium");
        ElementArr[111].atomicnum = 112;
        ElementArr[111].weight = 285;

        // Nihonium
        strcpy(ElementArr[112].name, "Nihonium");
        ElementArr[112].atomicnum = 113;
        ElementArr[112].weight = 286;

        // Flerovium
        strcpy(ElementArr[113].name, "Flerovium");
        ElementArr[113].atomicnum = 114;
        ElementArr[113].weight = 289;

        // Moscovium
        strcpy(ElementArr[114].name, "Moscovium");
        ElementArr[114].atomicnum = 115;
        ElementArr[114].weight = 290;

        // Livermorium
        strcpy(ElementArr[115].name, "Livermorium");
        ElementArr[115].atomicnum = 116;
        ElementArr[115].weight = 293;

        // Tennessine
        strcpy(ElementArr[116].name, "Tennessine");
        ElementArr[116].atomicnum = 117;
        ElementArr[116].weight = 294;

        // Oganesson
        strcpy(ElementArr[117].name, "Oganesson");
        ElementArr[117].atomicnum = 118;
        ElementArr[117].weight = 294;
    }
    // ACTION

    MenuAction();
    return 0;
}
