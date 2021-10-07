import sys
from PyQt5.QtCore import *
from PyQt5.QtGui  import *
from PyQt5.QtWidgets import QWidget, QDesktopWidget, QMainWindow

#own classes
from ui.widgets.button import Button

class MainWindow(QMainWindow):

    def __init__(self, parent=None):
        '''constructor'''
        QMainWindow.__init__(self, parent)
        self.setGeometry(0, 0, 650, 550)
        self.setWindowTitle("Financial Manager")
        self.center_window()

    def init_ui(self):
        self.create_record_button = Button(self)
        self.create_record_button.setText('create new record')

        self.show()

    def center_window(self):
        # geometry of the main window
        geometry = self.frameGeometry()
        center_point = QDesktopWidget().availableGeometry().center()
        geometry.moveCenter(center_point)
        # top left of rectangle becomes top left of window centering it
        self.move(geometry.topLeft())