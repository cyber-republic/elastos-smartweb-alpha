
## elastos 钱包对象结构文档

### 一、账户系统
#### 1、钱包对象

钱包账户——助记词——主私钥   一对一

| 字段名 | 内容 | 类型 | 备注 |
| ------ | ---- | ---- | ---- |
|     walletName   |  钱包A    |   char   |  钱包名称    |
|     mnemonic   |  一  而  我    |   char   |  助记词（明文）    |
|     mnemonicEncrypted   |xxxx   |   char   |  助记词（密文）    |
|     xPubKey   |  xxxxx    |   char   |  主公钥 （明文）   |
|     xPrivKeyEncrypted   |  xxxx    |   char   |  主私钥（密文）    |



#### 2、链（币种）对象

| 字段名 | 内容 | 类型 | 备注 |
| ------ | ---- | ---- | ---- |
|     coin   |  ela    |   char   |  币种代号   |
|     coinName   |  钱包A    |   char   |  币种全称   |
|     xPubKey   |  xxxxx    |   char   |  子公钥+链码 （明文）   |
|     xPrivKeyEncrypted   |  xxxx    |   char   |  子公钥+链码（密文）    |
|     addr   |  xxxx    |   char   |  地址  ||
|     walletPrivKey   |  xxxx    |   char   |  子私钥   |
|     walletPubKey   |  xxxx    |   char   |  子公钥   |
|     chaincode   |  xxxx    |   char   |  链码   |
|     network   |  livenet    |   char   |  网络状态    |
|     addressType   |  eumn|   类型   | single 普通地址 multi 多签地址     |


#### 3、地址对象


| 字段名 | 内容 | 类型 | 备注 |
| ------ | ---- | ---- | ---- |
|     hash   |  xxxxx    |   *Uint168   |  地址   |
|     script   |  xxx    |   char   |  与地址关联的一个脚本   |
|     addrType   |  1    |   int   |  地址类型  single 普通地址 multi 多签地址 |




#### 4、交易对象

| 字段名 | 内容 | 类型 | 备注 |
| ------ | ---- | ---- | ---- |
|     txid   |  xxxxx    |   char   |  交易id   |
|     script   |  xxx    |   char   |  与地址关联的一个脚本   |
|     action   |  xxx    |   int   |  状态  send发送6    received 接收6  moved 确认中1  balading打包中0  error 失败  |
|     time   |  1    |   time   |  交易时间 （块高查询） |
|     amount   |  1    |   int   |  交易额  |
|     fees   |  1    |   int   |  交易手续费 |
|     amountStr   |  1    |   char   |  格式化的交易额  |
|     feesStr   |  1    |   char   |  格式化的手续费  |
|     coin   |  1    |   char   |  代币的类型  |
|     addressTo   |  1    |   char   |  目标地址  |
|     addressFrom   |  1    |   char   |  发送地址  |
|     blockHight   |  1    |   int   |  块高  |
|     actionCount   |  1    |   int   |  确认次数  |






#### 5、联系人对象

| 字段名 | 内容 | 类型 | 备注 |
| ------ | ---- | ---- | ---- |
|     name   |  xxxxx    |   char   |  名字   |
|     addr   |  xxx    |   Uint168   |  地址   |
|     email   |  1    |   char   |  邮箱  |
|     phone   |  1    |   char   |  手机 |
|     remark   |  1    |   char   |  备注  |



#### 6、UTXO对象

| 字段名 | 内容 | 类型 | 备注 |
| ------ | ---- | ---- | ---- |
|     OutPoint   |  xxxxx    |   char   |  输出信息   |
|     Value   |  xxx    |   int   |     |
|     LockTime   |  1    |   int   |  锁定高度时间  |
|     AtHeight   |  1    |   int   |  块高 |







web钱包导出私钥json
    {"iv":"5op32yToGze2a6DX45gnrQ==","v":1,"iter":10000,"ks":128,"ts":64,"mode":"ccm","adata":"","cipher":"aes","salt":"hVTUUtptz0E=","ct":"6zCFLuoMJOarPYjmW4bcsGGFhWfUiK681PNdtJhj5+I18pHOA4CaBu6W6xzVzWX6e9mnRms0gjqTbOTgY7UdLu5vgDNGJwR7Jv5D/psJBDeGhBl/nqSmFJhVVYfwDaUQo1icSg+cIiZGt7pLgUVRxcCrW0sGpQnc9i4CY9Jd+TRfk6kOBzJEcwKMchKMfxGLNVRlcQaTq0foq1PqXApyXqwA13/oeHFRXIvYnjs//sbm2QkVZLklg3jgatg4DJcr2LoQFCgVH3dw6q0Pc+MeNdwE/ndGvosIePlB7mffjTbXUWFGUIG8qAD1o79PKWnNSyT0KQTEW4oe0N3CYJWpQBzicmCQTzdUVT1ZhRGp+rdXQRYtLs7G+aSp6NV+/+UfBe/Hoag77BGUQ2u8mnlOxNsNqrJkxrPPXc44ieoYqKn/sMr3DIrxqQapAgjdZ6v6/HmUf2Qh+jbJd3qlBv2jwks7W/mbzPfXQHXnoiUGW3rQFrxQ0Qz7TQikxMUlIC6PHBbD3rIA8/X+h97sKAWwru1v2tUyHbN8uTsw4NT524HCeXCYECHOD7eyItXRKwqBBSFHGcHeEIFgWnZwZAqQLrdyzbLOS5+3EczBcsyCQTejHKj6mXn7w8Lx3XgZoz8Pl86vko4jWz+9fWKkXtQXkBjf+p7e3/6rqKT35sNb8QlSzChhckuLCTuTZezHsaR6Sp6xW/6pwyX6TMCA90b8CPvlKdziSTOZuIa8mTWTwa+3c7yEim/baC7bKG2ZseXcSOilR3tcjzDfPPZxxyN+qIjW+THPh0I22jkp9j/IO0yxd/YsFSv/fmAZJ/dYb44R0E3QdpHz7ZgCPXOhuhtqg8a05Zn9Kb3edACQxVIMYStvrnUfamo9xtgircoeGaWPEA0bm8N6OOVvgqP4BSbCfqIu/Fl28eaB1mq8i4oMkdoiRO/IrDte3HUWlU1jcSy2PYXGWtqreiQGhMwbMXg5eF6FqCGx6e2It23aXdkdEwJdyaM5Oo6oHIaK2puIL5wJ2dYxlxsZQGOOIHv+NSfPBzCR8jmBGRJix0Olwuwd4ZgvNlXZocGEJTU01+ayLGUfS+u/55KaS7hZiXX2D37qDBCS8ajr6X5HRQcxanMMsnx7x7GjdgrPPEjtKfDmLNCoowtlPDX1ew2zLlGF7bMmyxZrFS3wzqmOSr/4lMbXhe5mJXMDQvq5sE0ccL8Wn5JGmDlZSOUsLYatyUyCohR0dTdTV4bBpF7SbodZy3FYGgZH/I4jhPRAz9hRQTJZbPLQmtZvpSE9zF2zA7w/j7bi+OM0Nq4Vgv6VbqwjTjO3B+U/ewHaB8fdvb7onZxW2E0Hg18JjXX+Wxvq8oTtORwJ5cp3731BkpUGhdE0uiqer3R8vHTniqyAkExTWA6NKg6N/tInAQHR640llhYVhoonnPNnLm2N1hobdtz0HX0YImX3KJtyt6cYf9xvCJ1OhaWEfJPNnwJZEjD274nYLP7JqscH0X269CxufU758Lw2Y6SNB8bd1nXzSYBjVHe4FKxJzX2ghCq6hbSMXG1s5SNXHGsm6i1o8Hfz/o4gBRwg8bLGN1Mdz1hyJq1IhPbxHAYPuiQwOQf70uTC7qt2J+wffwDgAZ1hg4nb7Y+F6TH49pYlOqbp8bCtsYYg/LYR4FI4HUlgQ8DNcOpF2H/RbVUb3Pp4PGqtO9nKMB5Px2Qe9Bu0VDP3LL7GRMSveBE1hrYOjWpjHIv3Gy6768RB5TCPQZQEWE2+pC8KhTTGVW9MI4L+T3p+kJmNSi9WHZLTKBKnjA=="}

