#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    private:
        Pos* pos;
        wchar_t symbol;

    public:
        objPos();
        objPos(int xPos, int yPos, wchar_t sym);
        objPos(const objPos &o);
        objPos& operator = (const objPos &o);
        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
        ~objPos();
        
        void setObjPos(objPos o);
        void setObjPos(int xPos, int yPos, wchar_t sym);

        objPos getObjPos() const;
        wchar_t getSymbol() const;
        int getX(); // Get Row Number/x-value
        int getY(); // Get Column Number/y-value
        wchar_t getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif