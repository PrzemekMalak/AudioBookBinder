//
//  AudioBookBinderAppDelegate.h
//  AudioBookBinder
//
//  Created by Oleksandr Tymoshenko on 10-02-04.
//  Copyright 2010 Bluezbox Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#import "AudioFileList.h"
#import "AudioBinder.h"
#import "CoverImageView.h"
#import <AppKit/NSSound.h>

#ifndef APP_STORE_BUILD
@class SUUpdater;
#endif

@interface AudioBookBinderAppDelegate : NSObject <AudioBinderDelegate, NSSoundDelegate, NSTextFieldDelegate> {
    IBOutlet NSWindow *window;
    IBOutlet NSOutlineView *fileListView;
    IBOutlet NSForm *form;
    IBOutlet NSButton *bindButton;
    IBOutlet NSProgressIndicator *fileProgress;
    IBOutlet NSPanel *progressPanel;
    IBOutlet NSTextField *currentFile;
    IBOutlet NSTabView *tabs;
    IBOutlet NSMenu *applicationMenu;
    IBOutlet AudioFileList *fileList;
    IBOutlet CoverImageView *coverImageView;
    IBOutlet NSButton *playButton;
    IBOutlet NSPopUpButton *genresButton;
    IBOutlet NSTextField *genresField;
    IBOutlet NSPanel *saveAsPanel;
    IBOutlet NSTextField *saveAsFilename;

    NSMutableArray *knownGenres;
    BOOL autocompleting;
    BOOL _playing;
    NSString *outFile;
    AudioBinder *_binder;
    NSArray *validBitrates;
    NSSound *_sound;
    NSString *_playingFile;
    NSImage *_playImg, *_stopImg;
    NSURL *_destURL;
    BOOL canPlay;
    BOOL _conversionResult;
#ifndef APP_STORE_BUILD
    IBOutlet SUUpdater *updater;
#endif
    
    NSMutableArray *currentColumns;
    
    UInt64 _estTotalDuration;
    UInt64 _currentDuration;
    UInt64 _currentProgress;
    NSImage *_appIcon;
};

@property (readwrite, retain) NSArray *validBitrates;
@property (readwrite, assign) BOOL canPlay;
+ (void) initialize;

- (IBAction) addFiles: (id)sender;
- (IBAction) delFiles: (id)sender;
- (IBAction) setCover: (id)sender;
- (IBAction) bind: (id)sender;
- (IBAction) cancel: (id)sender;
- (IBAction) chapterModeWillChange: (id)sender;
- (IBAction) joinFiles: (id)sender;
- (IBAction) splitFiles: (id)sender;
- (IBAction) renumberChapters: (id)sender;
- (IBAction) updateValidBitrates: (id)sender;
- (IBAction) playStop: (id)sender;
- (IBAction) openChaptersHowTo: (id)sender;

- (IBAction) saveAsOk:(id)sender;
- (IBAction) saveAsCancel:(id)sender;

#ifndef APP_STORE_BUILD
- (IBAction) checkForUpdates: (id)sender;
#endif

- (void) bindingThreadIsDone: (id) sender;
- (void) fixupBitrate;

- (BOOL) windowShouldClose:(NSNotification *)notification;
- (void) addFileToiTunes:(NSString *)path;
/*
 * The following method is called to put the MetaData read from the added AudioFiles MetaData into the ui fields.
 */
- (void) updateGuiWithGuessedData;

- (void) playFailed;
// NSSoundDelegate methods
- (void)sound:(NSSound *)sound didFinishPlaying:(BOOL)finishedPlaying;

- (void)updateTotalProgress;
- (void)resetTotalProgress;


@end
