// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The VirtaCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

//
// Main network
//

unsigned int pnSeed[] =
{
    0x11285336
};

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xbe;
        pchMessageStart[1] = 0xd0;
        pchMessageStart[2] = 0xc8;
        pchMessageStart[3] = 0xd1;
        vAlertPubKey = ParseHex("049A9B3745196E110827EF517F74ED5EA8E7F101C857661386AEC7066EDB213B313EC7D60E36327A022D86255CE7228D0090DBF62EF51F8DEFB54E438016BA990E");
        nRPCPort = 22815;
        nDefaultPort = 22816;
        
        //static CBigNum bnProofOfWorkLimit(~uint256(0) >> 20);
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        //nSubsidyHalvingInterval = 210000;

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
        // CBlock(hash=5f33a78519f106f8a557, PoW=00000ced5fae77960d63, ver=1, hashPrevBlock=00000000000000000000, hashMerkleRoot=2048624647, nTime=1401148056, nBits=1e0ffff0, nNonce=645406, vtx=1)
        //  CTransaction(hash=2048624647, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //    CTxIn(COutPoint(0000000000, -1), coinbase 04ffff001d01044c5254686520477561726469616e202d203236204d61792032303134202d204d6172696f204472616768692068696e74732061742045434220726174652063757420746f2061766f6964206465666c6174696f6e)
        //    CTxOut(nValue=0.00008000, scriptPubKey=045c6f57ad6d390a829c7e7c9528ab)
        //  vMerkleTree: 2048624647

        const char* pszTimestamp = "The Guardian - 26 May 2014 - Mario Draghi hints at ECB rate cut to avoid deflation";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CBigNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 8000;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("045C6F57AD6D390A829C7E7C9528AB0BF6D81333DD33EE8E3B5FDD006A60A6E4AC45B39D010D56D377305BB6B3ACCA55D3E3E789B15C2DAC0F91D35E348C71B94A") << OP_CHECKSIG;          
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1401148056;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 645406;
        
        hashGenesisBlock = genesis.GetHash();
        
        assert(hashGenesisBlock == uint256("0x5f33a78519f106f8a557e2ebf241e5d48399b6e1ee30430ea8027be9cbd5a376"));
        assert(genesis.hashMerkleRoot == uint256("0x2048624647cd974ffbc7a8089ece6c46a57e5f06b5f3b16dd64a68b889aa87cb"));
        
        vSeeds.push_back(CDNSSeedData("virtacoin.com seed 1", "seed1.virtacoin.com"));
        vSeeds.push_back(CDNSSeedData("virtacoin.com seed 2", "seed2.virtacoin.com"));

        base58Prefixes[PUBKEY_ADDRESS] = list_of(0);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(5);
        base58Prefixes[SECRET_KEY] =     list_of(128);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);

        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const int64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet (v3)
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xfc;
        pchMessageStart[1] = 0xc1;
        pchMessageStart[2] = 0xb7;
        pchMessageStart[3] = 0xdc;
        vAlertPubKey = ParseHex("b5dca8039e300198e5fe7cd23bdd1728e2a444af34c447dbd0916fa3430a68c2");
        nDefaultPort = 12025;
        nRPCPort = 14023;
        strDataDir = "testnet3";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1392796564;
        genesis.nNonce = 961533;
        hashGenesisBlock = genesis.GetHash();
        // assert(hashGenesisBlock == uint256("0xb5dca8039e300198e5fe7cd23bdd1728e2a444af34c447dbd0916fa3430a68c2"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("", ""));

        base58Prefixes[PUBKEY_ADDRESS] = list_of(111);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(196);
        base58Prefixes[SECRET_KEY]     = list_of(239);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xb3;
        pchMessageStart[2] = 0xb2;
        pchMessageStart[3] = 0xdb;
        //nSubsidyHalvingInterval = 150;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1392796564;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 961533;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";
        //assert(hashGenesisBlock == uint256("0x0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
