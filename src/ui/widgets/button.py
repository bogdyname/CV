from PyQt5.QtWidgets import QPushButton

class Button(QPushButton):

    def __init__(self, parent=None):
        '''constructor'''
        QPushButton.__init__(self, parent)