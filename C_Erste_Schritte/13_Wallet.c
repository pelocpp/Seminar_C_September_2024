// =====================================================================================
// Wallet.c
// =====================================================================================

#include <stdio.h>

#include "Wallet.h"

// =====================================================================================
// Implementation

void init(struct Wallet* wallet, unsigned long long euros, unsigned int cents)
{
    if (cents >= 100) {
        printf("Cents larger than 100 are not allowed!\n");
        wallet->m_cents = 0;
    }
    else {
        wallet->m_cents = cents;
    }

    wallet->m_euros = euros;
}

static unsigned long long getEuros(struct Wallet* wallet)
{
    // printf("....");
    // check
    return wallet->m_euros;
}

static unsigned int getCent(struct Wallet* wallet)
{
    return wallet->m_cents;
}

void addWallet(struct Wallet* wallet, struct Wallet* other)
{
    wallet->m_cents = wallet->m_cents + other->m_cents;
    unsigned int carry = wallet->m_cents / 100;
    wallet->m_cents = wallet->m_cents % 100;
    wallet->m_euros = wallet->m_euros + other->m_euros + carry;
}

void addEuros(struct Wallet* wallet, unsigned long long euros)
{
    wallet->m_euros = wallet->m_euros + euros;
}

void addEurosAndCents(struct Wallet* wallet, unsigned long long euros, unsigned int cents)
{
    struct Wallet tmp = { euros, cents };

    addWallet(wallet, &tmp);
}

static int subWallet(struct Wallet* wallet, struct Wallet* other)
{
    if (lessThan(wallet, other)) {
        printf("Not enough money available in wallet!\n");
        return 0;
    }

    // underrun
    if (wallet->m_cents < other->m_cents)
    {
        wallet->m_euros = wallet->m_euros - 1;
        wallet->m_cents = wallet->m_cents + 100;
    }

    wallet->m_euros = wallet->m_euros - other->m_euros;
    wallet->m_cents = wallet->m_cents - other->m_cents;

    return 1;
}

static int subEuros(struct Wallet* wallet, unsigned long long euros)
{
    if (wallet->m_euros < euros) {
        printf("Not enough money available in wallet!\n");
        return 0;
    }

    wallet->m_euros = wallet->m_euros - euros;

    return 1;
}

static int subEurosAndCents(struct Wallet* wallet, unsigned long long euros, unsigned int cents)
{
    struct Wallet tmp = { euros, cents };

    return subWallet(wallet, &tmp);
}

static int lessThan(struct Wallet* wallet, struct Wallet* other)
{
    if (wallet->m_euros < other->m_euros) {
        return 1;
    }
    else if (wallet->m_euros == other->m_euros && wallet->m_cents < other->m_cents) {
        return 1;
    }
    else {
        return 0;
    }
}

static int equals(struct Wallet* wallet, struct Wallet* other)
{
    if (wallet->m_euros == other->m_euros && wallet->m_cents == other->m_cents) {
        return 1;
    }
    else {
        return 0;
    }
}

static unsigned long long toCents(struct Wallet* wallet)
{
    return 100 * wallet->m_euros + wallet->m_cents;
}

void print(struct Wallet* wallet)
{
    printf("%llu,%02u Euro\n", wallet->m_euros, wallet->m_cents);
}

void exercise_wallet_01()
{
    struct Wallet wallet = { 0, 0 };

    print(&wallet);

    addEurosAndCents(&wallet, 10, 50);
    print(&wallet);

    subEurosAndCents(&wallet, 5, 75);
    print(&wallet);

    unsigned long long cents = toCents(&wallet);
    printf("Cents: %llu\n", cents);
}

static void exercise_wallet_02()
{
    struct Wallet wallet1 = { 3, 30 };
    struct Wallet wallet2 = { 3, 30 };

    print(&wallet1);
    print(&wallet2);

    int equal = equals(&wallet1, &wallet2);
    printf("Wallets are equal: %d\n", equal);

    subEurosAndCents(&wallet1, 3, 28);
    print(&wallet1);

    subEurosAndCents(&wallet1, 0, 1);
    print(&wallet1);

    subEurosAndCents(&wallet1, 0, 1);
    print(&wallet1);

    subEurosAndCents(&wallet1, 0, 1);
    print(&wallet1);
}

static void exercise_wallet_03()
{
    struct Wallet wallet1 = { 123, 45 };
    struct Wallet wallet2 = { 3, 30 };
    struct Wallet wallet3 = { 3, 30 };

    print(&wallet1);

    addWallet(&wallet1, &wallet2);
    print(&wallet1);

    addWallet(&wallet1, &wallet3);
    print(&wallet1);

    unsigned long long cents = toCents(&wallet1);
    printf("Cents: %llu\n", cents);
}

static void exercise_wallet_04()
{
    //int zahlen[10000000];
    //int zahlen[] = new int[10000000];


    // C/C++ // C# // Java (Zeiger / Referenz)
    //struct Wallet wallet = new Wallet();
    //if (wallet == Null)

    struct Wallet wallet1 = { 0, 3 };
    struct Wallet wallet2 = { 0, 1 };

    print(&wallet1);

    subWallet(&wallet1, &wallet2);
    print(&wallet1);

    subWallet(&wallet1, &wallet2);
    print(&wallet1);

    subWallet(&wallet1, &wallet2);
    print(&wallet1);

    subWallet(&wallet1, &wallet2);
    print(&wallet1);
}

void exercise_wallet()
{
    exercise_wallet_01();
    exercise_wallet_02();
    exercise_wallet_03();
    exercise_wallet_04();
}

// =====================================================================================
// End-of-File
// =====================================================================================