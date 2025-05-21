#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <openssl/sha.h>

// Utility functions
std::vector<unsigned char> ParseHex(const char* psz)
{
    std::vector<unsigned char> vch;
    while (true)
    {
        while (isspace(*psz))
            psz++;
        signed char c = HexDigit(*psz++);
        if (c == (signed char)-1)
            break;
        unsigned char n = (c << 4);
        c = HexDigit(*psz++);
        if (c == (signed char)-1)
            break;
        n |= c;
        vch.push_back(n);
    }
    return vch;
}

signed char HexDigit(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else
        return -1;
}

// Simplified block header structure
struct BlockHeader {
    int32_t nVersion;
    uint256 hashPrevBlock;
    uint256 hashMerkleRoot;
    uint32_t nTime;
    uint32_t nBits;
    uint32_t nNonce;
    
    BlockHeader() {
        nVersion = 1;
        hashPrevBlock.SetNull();
        hashMerkleRoot.SetNull();
        nTime = 1747267200; // May 21, 2025
        nBits = 0x1d00ffff;
        nNonce = 0;
    }
    
    uint256 GetHash() const {
        return SerializeHash(*this);
    }
};

// Main function to mine the genesis block
int main() {
    BlockHeader genesis;
    
    // Set the merkle root (this would be calculated from the coinbase transaction)
    // For simplicity, we'll use a placeholder
    genesis.hashMerkleRoot = uint256S("0x4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b");
    
    // Target difficulty
    uint256 target;
    target.SetCompact(genesis.nBits);
    
    std::cout << "Mining genesis block..." << std::endl;
    std::cout << "Target: " << target.ToString() << std::endl;
    
    // Mine the block
    while (true) {
        uint256 hash = genesis.GetHash();
        if (hash <= target) {
            std::cout << "Found valid genesis block!" << std::endl;
            std::cout << "Nonce: " << genesis.nNonce << std::endl;
            std::cout << "Hash: " << hash.ToString() << std::endl;
            break;
        }
        
        if (genesis.nNonce % 1000000 == 0) {
            std::cout << "Nonce: " << genesis.nNonce << ", Hash: " << hash.ToString() << std::endl;
        }
        
        genesis.nNonce++;
    }
    
    return 0;
}