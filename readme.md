# react-native银联插件

## 安装

###本组件基于react-natve 最新版本 0.52  其他版本请自行测试

```
yarn add  react-native-unionpay-control

npm install react-native-unionpay-control --save

react-native link react-native-unionpay-control
```

## IOS 配置
- 在工程info.plist设置中添加一个URL Types回调协议(在UPPayDemo工程中使用“UPPayDemo”作为协议)，用于在支付完成后返回商户客户端。

- http请求设置: 在Xcode7.0之后的版本中进行http请求时，需要在工程对应的plist文件中添加NSAppTransportSecurity  Dictionary 并同时设置里面NSAllowsArbitraryLoads 属性值为 YES
- 添加协议白名单: 在Xcode7.0之后的版本中进行开发，需要在工程对应的plist文件中，添加LSApplicationQueriesSchemes  Array并加入uppaysdk、uppaywallet、uppayx1、uppayx2、uppayx3五个item

###以上三步具体做法具体做法如下
1. info.plist 文件添加（存在请直接替换掉原有内容）如下内容：

```
<key>CFBundleURLTypes</key>
<array>
  <dict>
    <key>CFBundleTypeRole</key>
    <string>Editor</string>
    <key>CFBundleURLSchemes</key>
    <array>
      <string>unionpay</string>
    </array>
  </dict>
</array>
<key>LSApplicationQueriesSchemes</key>
<array>
  <string>uppaysdk</string>
  <string>uppaywallet</string>
  <string>uppayx1</string>
  <string>uppayx2</string>
  <string>uppayx3</string>
</array>
<key>NSAppTransportSecurity</key>
<dict>
  <key>NSAllowsArbitraryLoads</key>
  <true/>
  <key>NSExceptionDomains</key>
  <dict>
    <key>localhost</key>
    <dict>
      <key>NSExceptionAllowsInsecureHTTPLoads</key>
      <true/>
    </dict>
  </dict>
</dict>
```

2. AppDelegate.m 的 下面 @end 前面添加下面代码

```
#import <React/RCTLinkingManager.h>

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
  return [RCTLinkingManager application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
}
```

## 	调用插件

```
import * as Unionpay from 'react-native-unionpay-control'
/*
* tn 交易流水号，商户后台向银联后台提交订单信息后，由银联后台生成并下发给商户后台的交易凭证；
* mode 接入模式，标识商户以何种方式调用支付控件，该参数提供以下两个可选值："00"代表接入生产环境（正式版本需要）；"01"代表接入开发测试环境（测试版本需要）；
*/
Unionpay.startPay(tn, mode)
.then(res => {
	console.log(res, 'see payment res');
})
catch(err => {
	//检查返回的对象有code属性
	if(typeof err == 'object' && err.code) {
		//code 当失败的时候值有：fail,cancel
	}
	console.warn(err, 'payment failed ');
})
```

# 测试账号
- 以下是测试用卡号、手机号等信息（此类信息仅供测试使用，不会发生真实交易）
  [银联官方](https://open.unionpay.com/ajweb/product/newProDetail?proId=3)

  招商银行借记卡：6226090000000048  
  手机号：18100000000  
  密码：111101
  短信验证码：123456（先点获取验证码之后再输入）  
  证件类型：01身份证  
  证件号：510265790128303  
  姓名：张三

  华夏银行贷记卡：6226388000000095
  手机号：18100000000
  CVN2：248
  有效期：1219
  短信验证码：123456（先点获取验证码之后再输入）
  证件类型：01身份证
  证件号：510265790128303
  姓名：张三
