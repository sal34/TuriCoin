TuriCoin integration/staging tree
=====================================

https://github.com/sal34/TuriCoin

TuriCoin is a fork of Bitcoin Core with modified parameters.

What is TuriCoin?
---------------------

TuriCoin is a cryptocurrency that connects to its own peer-to-peer network to download and fully
validate blocks and transactions. It also includes a wallet and graphical user
interface, which can be optionally built.

TuriCoin features:
- 10 second block time (vs Bitcoin's 10 minutes)
- Difficulty adjustment every 720 blocks (approximately once per day)
- Custom address format starting with 'T'
- New genesis block created on May 21, 2025

## Genesis Block Parameters

The genesis blocks for all networks have been modified with the following parameters:

### Mainnet
- Hash: `1c9cc008e6ba7860db19edae99052c3a0d22e5dfce5fffb5d9f90b1559dd320e`
- Merkle Root: `9197e97f6b8b25bb7d752fbcf7a633fb2da64052ba3dfd73bf8cb0ef47eb28d1`
- Timestamp: 1296688602 (February 2, 2011)
- Nonce: 2
- Bits: 0x1d00ffff

### Testnet
- Hash: `61901b477d2f833c6a8161b79b7508dbd7b79df9cc66ae4c2d48683beff1ea3f`
- Merkle Root: `9197e97f6b8b25bb7d752fbcf7a633fb2da64052ba3dfd73bf8cb0ef47eb28d1`
- Timestamp: 1296688602 (February 2, 2011)
- Nonce: 2
- Bits: 0x1d00ffff

### Testnet4
- Hash: `b419e710e8f282f5a8c5b01d6c8c4a63e5efb005f98784d8177c699f67b94b55`
- Merkle Root: `9197e97f6b8b25bb7d752fbcf7a633fb2da64052ba3dfd73bf8cb0ef47eb28d1`
- Timestamp: 1296688602 (February 2, 2011)
- Nonce: 2
- Bits: 0x1d00ffff

### Signet
- Hash: `aea9f1c403c04ab40dd2cb90cd90494667512677750323e82bd8a9a1441b5ec2`
- Merkle Root: `9197e97f6b8b25bb7d752fbcf7a633fb2da64052ba3dfd73bf8cb0ef47eb28d1`
- Timestamp: 1296688602 (February 2, 2011)
- Nonce: 2
- Bits: 0x1d00ffff

### Regtest
- Hash: `a5a67afda65968cf23c1bdd988c46c2dec6d5f627629eb676a4ef63eaa8711c6`
- Merkle Root: `9197e97f6b8b25bb7d752fbcf7a633fb2da64052ba3dfd73bf8cb0ef47eb28d1`
- Timestamp: 1296688602 (February 2, 2011)
- Nonce: 1
- Bits: 0x207fffff

## Running in Regtest Mode

```bash
# Run in regtest mode
./bin/turicoind -regtest

# Create a wallet
./bin/turicoin-cli -regtest createwallet "mywallet"

# Generate blocks
./bin/turicoin-cli -regtest -rpcwallet=mywallet generatetoaddress 101 $(./bin/turicoin-cli -regtest -rpcwallet=mywallet getnewaddress)

# Check balance
./bin/turicoin-cli -regtest -rpcwallet=mywallet getbalance
```

Further information about TuriCoin is available in the [doc folder](/doc).

License
-------

Bitcoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/license/MIT.

Development Process
-------------------

The `master` branch is regularly built (see `doc/build-*.md` for instructions) and tested, but it is not guaranteed to be
completely stable. [Tags](https://github.com/bitcoin/bitcoin/tags) are created
regularly from release branches to indicate new official, stable release versions of Bitcoin Core.

The https://github.com/bitcoin-core/gui repository is used exclusively for the
development of the GUI. Its master branch is identical in all monotree
repositories. Release branches and tags do not exist, so please do not fork
that repository unless it is for development reasons.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md)
and useful hints for developers can be found in [doc/developer-notes.md](doc/developer-notes.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled during the generation of the build system) with: `ctest`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python.
These tests can be run (if the [test dependencies](/test) are installed) with: `build/test/functional/test_runner.py`
(assuming `build` is your build directory).

The CI (Continuous Integration) systems make sure that every pull request is built for Windows, Linux, and macOS,
and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[Bitcoin Core's Transifex page](https://www.transifex.com/bitcoin/bitcoin/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.
