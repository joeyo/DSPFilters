/*******************************************************************************

"A Collection of Useful C++ Classes for Digital Signal Processing"
 By Vincent Falco

Official project location:
http://code.google.com/p/dspfilterscpp/

See Documentation.h for contact information, notes, and bibliography.

--------------------------------------------------------------------------------

License: MIT License (http://www.opensource.org/licenses/mit-license.php)
Copyright (c) 2009 by Vincent Falco

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*******************************************************************************/

#include "ContentComponentConstrainer.h"
#include "MainWindow.h"
#include "DemoPanel.h"
#include "MainPanel.h"

MainWindow::MainWindow () 
  : DocumentWindow (TRANS("Dsp Filters Demo"),
                    Colours::lightgrey, 
                    DocumentWindow::allButtons,
                    true)
{
  setResizable (true, false);
  
#if 0
  DemoPanel* contentComponent = new DemoPanel;
  setMenuBar (contentComponent);
  setContentComponent (contentComponent, true, true);
#else
  MainPanel* contentComponent = new MainPanel;
  setMenuBar (contentComponent);
  setContentComponent (contentComponent, true, true);
  contentComponent->setAsConstrainerFor (this);
  ContentComponentConstrainer::attachTo (this);
#endif

  centreWithSize (getWidth(), getHeight());
  setVisible (true);
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeButtonPressed()
{
  JUCEApplication::quit();
}