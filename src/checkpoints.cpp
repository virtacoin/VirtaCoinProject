// Copyright (c) 2009-2014 The VirtaCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

#include <stdint.h>

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    // How many times we expect transactions after the last checkpoint to
    // be slower. This number is a compromise, as it can't be accurate for
    // every system. When reindexing from a fast disk with a slow CPU, it
    // can be up to 20, while when downloading from a slow network with a
    // fast multicore CPU, it won't be much higher than 1.
    static const double fSigcheckVerificationFactor = 5.0;

    struct CCheckpointData {
        const MapCheckpoints *mapCheckpoints;
        int64_t nTimeLastCheckpoint;
        int64_t nTransactionsLastCheckpoint;
        double fTransactionsPerDay;
    };

    bool fEnabled = true;

    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (     0, uint256("0x5f33a78519f106f8a557e2ebf241e5d48399b6e1ee30430ea8027be9cbd5a376"))
        (   100, uint256("0x672ed780e35939a68854a73c10b91db3d9cd676ae97f0a3e56346a0cc5944bda"))
        (   200, uint256("0x50565f5087eedf6a7994ba1904a7dd02236f585666aeee843c3a20b231e48ace"))
        (   300, uint256("0x09b3f5052f834b00828c1397108e3167a19534599c8495b98b86e7641f87742e"))
        (   400, uint256("0x7235ff00d2c56de9d425d0678894f5906b15ae1c9560ab2e3b334c590c095214"))
        (   500, uint256("0x9a61d1b2ff818e81d44ccdd6fbeb8dc931fecec090c707b64029b7eac75fba62"))
        (   600, uint256("0x5a5ca3315be03f24add3cd1faee27166d2f2d50d8355807b974408b5ccffd9da"))
        (   700, uint256("0x22f2ce7ee3ac5aa86d5171324230f6219d428e72e7d9520c0fd7a78eab713035"))
        (   800, uint256("0xae2f10b5c501c953badeb3ab62df0fe5df682c9547d314dd4bd5942e12856b99"))
        (   900, uint256("0x1dd898de078a48ddbf6b7817c6ff53864d5474853b319764354f5c82f041645d"))
        (  1000, uint256("0x55618571c7b4f046a6fe6fe1f184e2de1106ee712cc296f43bb5b8dcdd905a8d"))
        (  1100, uint256("0x4fc8102fb2a07fdf626e9bc950df2f71bd2050df50afad95a6a86dcf0340ba67"))
        (  1200, uint256("0x779028583edcd25758c22584d4de0448baebe99c80ef895e78302fc316021ca9"))
        (  1300, uint256("0xc58a7b6be04f3a47ad3ea9417ab6f6aa770b80bb9512fb1615100216a40817ed"))
        (  1400, uint256("0x426c142afc4cc58399091ab350eab28e75e07a773188603c42a78057eb1f1d97"))
        (  1500, uint256("0x5cb5cf98871f2a2cb738df0ec5c504bfbbeab724d53f9c1765e7e8b9341578cb"))
        (  1600, uint256("0x1b385be25df3be55e99398a0948c6bbeb8711dc5aa3bcf538057576db7609487"))
        (  1700, uint256("0x9c1d1c8c972d9d96e5fc46b2816508c413096fb3fa38007575d7b3cf2ab7de15"))
        (  1800, uint256("0x0b0d734083cc696e67e26aa30790c27925ce4cd964bd85d304520f6f6de12fd9"))
        (  1900, uint256("0xf83327ac4595dcc2f580221d355b3444fe188c07e62e0e1554495d6fade18d41"))
        (  2000, uint256("0x703a9e4eb09c9765ae69cbf9b5c7d23b801568f9d83aa51b7369d8ba0739a301"))
        (  2100, uint256("0xc4767d54cc064742634bec45bf186a7ea41d760e00e69d481e414fdcb86ec177"))
        (  2110, uint256("0x4bc411211020d5d874cfb8ab0f5e8e4384b1e902ab0da7d522a6405209bf121f"))
        ;
    static const CCheckpointData data = {
        &mapCheckpoints,
        1403673787, // * UNIX timestamp of last checkpoint block
        1752206,   // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        1000.0     // * estimated number of transactions per day after checkpoint
    };

    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 546, uint256("0000000000000000000000000000000000000000000000000000000000000000"))
        ;
    static const CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        0,
        0,
        0
    };

    static MapCheckpoints mapCheckpointsRegtest =
        boost::assign::map_list_of
        ( 0, uint256("0000000000000000000000000000000000000000000000000000000000000000"))
        ;
    static const CCheckpointData dataRegtest = {
        &mapCheckpointsRegtest,
        0,
        0,
        0
    };

    const CCheckpointData &Checkpoints() {
        if (Params().NetworkID() == CChainParams::TESTNET)
            return dataTestnet;
        else if (Params().NetworkID() == CChainParams::MAIN)
            return data;
        else
            return dataRegtest;
    }

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (!fEnabled)
            return true;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    // Guess how far we are in the verification process at the given block index
    double GuessVerificationProgress(CBlockIndex *pindex) {
        if (pindex==NULL)
            return 0.0;

        int64_t nNow = time(NULL);

        double fWorkBefore = 0.0; // Amount of work done before pindex
        double fWorkAfter = 0.0;  // Amount of work left after pindex (estimated)
        // Work is defined as: 1.0 per transaction before the last checkpoint, and
        // fSigcheckVerificationFactor per transaction after.

        const CCheckpointData &data = Checkpoints();

        if (pindex->nChainTx <= data.nTransactionsLastCheckpoint) {
            double nCheapBefore = pindex->nChainTx;
            double nCheapAfter = data.nTransactionsLastCheckpoint - pindex->nChainTx;
            double nExpensiveAfter = (nNow - data.nTimeLastCheckpoint)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore;
            fWorkAfter = nCheapAfter + nExpensiveAfter*fSigcheckVerificationFactor;
        } else {
            double nCheapBefore = data.nTransactionsLastCheckpoint;
            double nExpensiveBefore = pindex->nChainTx - data.nTransactionsLastCheckpoint;
            double nExpensiveAfter = (nNow - pindex->nTime)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore + nExpensiveBefore*fSigcheckVerificationFactor;
            fWorkAfter = nExpensiveAfter*fSigcheckVerificationFactor;
        }

        return fWorkBefore / (fWorkBefore + fWorkAfter);
    }

    int GetTotalBlocksEstimate()
    {
        if (!fEnabled)
            return 0;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (!fEnabled)
            return NULL;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}

