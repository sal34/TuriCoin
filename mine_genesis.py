#!/usr/bin/env python3
import hashlib
import struct
import time

# Genesis block parameters
version = 1
prev_block = "0000000000000000000000000000000000000000000000000000000000000000"
merkle_root = "4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b"
timestamp = 1747267200  # May 21, 2025
bits = 0x1d00ffff
nonce = 0

# Target difficulty
def bits_to_target(bits):
    exp = bits >> 24
    mant = bits & 0xffffff
    target_hex = '%064x' % (mant * (1 << (8 * (exp - 3))))
    return int(target_hex, 16)

target = bits_to_target(bits)

# Function to calculate block hash
def calculate_hash(version, prev_block, merkle_root, timestamp, bits, nonce):
    header = struct.pack("<I", version) + \
             bytes.fromhex(prev_block)[::-1] + \
             bytes.fromhex(merkle_root)[::-1] + \
             struct.pack("<III", timestamp, bits, nonce)
    
    hash1 = hashlib.sha256(header).digest()
    hash2 = hashlib.sha256(hash1).digest()
    
    return hash2[::-1].hex()

print("Mining TuriCoin genesis block...")
print(f"Target: {target}")

start_time = time.time()
while True:
    block_hash = calculate_hash(version, prev_block, merkle_root, timestamp, bits, nonce)
    hash_int = int(block_hash, 16)
    
    if hash_int < target:
        elapsed = time.time() - start_time
        print(f"\nFound valid genesis block after {elapsed:.2f} seconds!")
        print(f"Nonce: {nonce}")
        print(f"Hash: {block_hash}")
        break
    
    if nonce % 100000 == 0:
        elapsed = time.time() - start_time
        print(f"Nonce: {nonce}, Hash: {block_hash}, Time: {elapsed:.2f}s", end="\r")
    
    nonce += 1