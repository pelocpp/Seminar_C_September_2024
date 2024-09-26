#pragma once

// =====================================================================================
// Wallet.h
// =====================================================================================

// #define 

// =====================================================================================
// Types

// Spielregeln

struct Wallet
{
    unsigned long long m_euros;
    unsigned int       m_cents;

    // Anmerkung: check ...

    // Produktiv Code:
    // einfacher: NUR CENT SPEICHERN !!!!

    // Name des Geldbeutels 

    // Überweisung
};

// typedef struct wallet Wallet;

// =====================================================================================
// Function Prototypes

// c'tor
void                init              (struct Wallet* wallet, unsigned long long euros, unsigned int cents);

// getter
// Kapselung simulieren
unsigned long long  getEuros          (struct Wallet* wallet);
unsigned int        getCent           (struct Wallet* wallet);

// settern 

// methods
void                addWallet         (struct Wallet* wallet, struct Wallet* other);
void                addEuros          (struct Wallet* wallet, unsigned long long euros);
void                addEurosAndCents  (struct Wallet* wallet, unsigned long long euros, unsigned int cents);
int                 subWallet         (struct Wallet* wallet, struct Wallet* other);
int                 subEuros          (struct Wallet* wallet, unsigned long long euros);
int                 subEurosAndCents  (struct Wallet* wallet, unsigned long long euros, unsigned int cents);
unsigned long long  toCents           (struct Wallet* wallet);
void                print             (struct Wallet* wallet);

// comparison methods // Operatoren überladen ==, !=, <=
int                 lessThan          (struct Wallet* wallet, struct Wallet* other);
int                 equals            (struct Wallet* wallet, struct Wallet* other);

// =====================================================================================
// End-of-File
// =====================================================================================