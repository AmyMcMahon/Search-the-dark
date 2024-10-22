# bookSearcher

## Index

### To Compile

```bash
cd indexer
make
```

### To Run

This will create an index of the files in `/books` and store it in `/index`.

```bash
cd indexer
touch indexedBooks.csv
cd ..
mkdir index
./indexer/indexer
```

### To Vefify

The `/index` directory should now contain multple csv's for each letter.

## Search

### To Compile

```bash
make 
```

### To Run

```bash
./main
```

### To Verify

| Search | Result (Amount of books returned) |
| --- | --- |
| `the` | 14 |
| `NOT her` | 7 |
| `water AND dead` | 3 |
| `slicer OR slasher` | 4 |
