//
//  RCTUnionpay.h
//  RCTUnionpay
//
//  Created by dingzhen on 1/25/18.
//  Copyright © 2016 dingzhen. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RCTBridgeModule.h"
#import "RCTLog.h"
#import "RCTEventDispatcher.h"
#import "RCTEventEmitter.h"
#import "UPPaymentControl.h"
#define URL_SCHEMES_NOT_DEFINED (@"URL scheme is not defined!")
#define START_PAY_FAILED (@"start pay failed")

@interface RCTUnionpay : RCTEventEmitter <RCTBridgeModule>
@property NSString* schemeStr;
@end
