# QAbstractTableModel

|               | AIO |Customize header row | Items are editable | Rows and columns can be added | Rows and columns can be removed | Fetch data dynamically |
| ------------- | --- | ------------------- | ------------------ | ----------------------------- | ------------------------------- | ---------------------- |
| headerData    | +   | +                   |                    |                               |                                 |                        |
| setHeaderData | +   |                     |                    |                               |                                 |                        |
| index         |     |                     |                    |                               | +                               |                        |
| parent        |     |                     |                    |                               | +                               |                        |
| rowCount      | +   | +                   | +                  | +                             | +                               | +                      |
| columnCount   | +   | +                   | +                  | +                             | +                               | +                      |
| data          | +   | +                   | +                  | +                             | +                               | +                      |
| setData       | +   |                     | +                  |                               |                                 |                        |
| flags         | +   |                     | +                  |                               |                                 |                        |
| insertRows    | +   |                     |                    | +                             |                                 |                        |
| insertColumns | +   |                     |                    | +                             |                                 |                        |
| removeRows    | +   |                     |                    |                               | +                               |                        |
| removeColumns | +   |                     |                    |                               | +                               |                        |
| hasChildren   |     |                     |                    |                               |                                 |                        |
| canFetchMore  |     |                     |                    |                               |                                 |                        |
| fetchMore     |     |                     |                    |                               |                                 |                        |
