import sys
from PyQt5.QtWidgets import QApplication

#own classes
from ui.main_window import MainWindow

if __name__ == '__main__':

    app = QApplication(sys.argv)

    mw = MainWindow()
    mw.init_ui()

    sys.exit(app.exec_())