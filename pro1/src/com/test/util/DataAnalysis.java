package com.test.util;

import com.test.pojo.Fuheplan;
import com.test.pojo2.Fuheplan2;
import com.test.service.FuheplanService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

/**
 * Created by 世康 on 2016/10/9.
 */
public class DataAnalysis {

    @Autowired
    private FuheplanService fuheplanService;

    @Autowired
    private com.test.service2.FuheplanService fuheplan2Service;

    private List<Fuheplan> list3;
    private List<Fuheplan2> list4;

    public List<Fuheplan2> getList4() {
        return list4;
    }

    public List<Fuheplan> getList3() {
        return list3;
    }

    public void Analysis() {
        list3 = fuheplanService.getFuheplanAll();
        list4 = fuheplan2Service.getFuheplanAll();

        list3.removeAll(list4);
        list4.removeAll(list3);
    }


}
