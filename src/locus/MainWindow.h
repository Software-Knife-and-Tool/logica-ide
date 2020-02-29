/*******
 **
 ** Copyright (c) 2017, James M. Putnam
 ** All rights reserved.
 **
 ** Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are met:
 **
 ** 1. Redistributions of source code must retain the above copyright notice,
 **    this list of conditions and the following disclaimer.
 **
 ** 2. Redistributions in binary form must reproduce the above copyright
 **    notice, this list of conditions and the following disclaimer in the
 **    documentation and/or other materials provided with the distribution.
 **
 ** 3. Neither the name of the copyright holder nor the names of its
 **    contributors may be used to endorse or promote products derived from
 **    this software without specific prior written permission.
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 ** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 ** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 ** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 ** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 ** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 ** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 ** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 ** POSSIBILITY OF SUCH DAMAGE.
 **
 *******/

/********
 **
 **  MainWindow.h: MainWindow class
 **
 **/

#ifndef _LOCUS_SRC_LOCUS_MAINWINDOW_H_
#define _LOCUS_SRC_LOCUS_MAINWINDOW_H_

#include <QMainWindow>
#include <QStatusBar>
#include <QTimer>
#include <QDateTime>
#include <QMdiArea>

#include "StatusClock.h"
#include "LocusFrame.h"
#include "MainMenuBar.h"
#include "Mu.h"

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QDateTime;
class QStatusBar;
QT_END_NAMESPACE

namespace locus {

class MainMenuBar;
class LocusFrame;
  
class MainWindow : public QMainWindow {

  Q_OBJECT

 public:
  locus::Mu* mu;
  
  MainWindow();

  void setContextStatus(const char*);
  
 protected:
  void contextMenuEvent(QContextMenuEvent *event) override;

 private:
  void createStatusBar();

 private:
  LocusFrame* locusFrame;
  MainMenuBar* mainMenuBar;
  QDateTime startTime;
  QMdiArea* mdiArea;
  // QLabel *infoLabel;
  StatusClock* statusClock;
};

} /* locus namespace */

#endif  /* _LOCUS_SRC_LOCUS_MAINWINDOW_H_ */
